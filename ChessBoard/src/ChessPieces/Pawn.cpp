//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Pawn.h"

bool Pawn::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (not baseCanMove) {
        return false;
    }

    bool isCorrectDirectionValue = isCorrectDirection(sourceY, destY);
    if (not isCorrectDirectionValue) {
        return false;
    }


    // TODO: IMPLEMENT EN PASSANT
    if (firstMove) {
        bool canMove = canMoveFirstTurn(sourceX, sourceY, destX, destY);

        if (canMove) {
            setUsedFirstMove();
        }

        return canMove;
    } else {
        bool canDiagonalCaptureValue = canDiagonalCapture(sourceX, sourceY, destX, destY);
        bool canMoveSingleSpaceValue = canMoveSingleSpace(sourceX, sourceY, destX, destY);

        return canDiagonalCaptureValue or canMoveSingleSpaceValue;
    }
}

bool Pawn::canDiagonalCapture(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);
    if (xAbsDistance == 1 and xAbsDistance == yAbsDistance) {
        bool isIndexOccupiedValue = ChessMovementMediator::isBoardIndexOccupied(destX, destY);
        return isIndexOccupiedValue;
    }

    return false;
}

// TODO: Check if space is not occupied
bool Pawn::canMoveSingleSpace(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool isTargetOccupiedValue = ChessMovementMediator::isBoardIndexOccupied(destX, destY);

    bool canMove = xAbsDistance == 0 and yAbsDistance < 2 and not isTargetOccupiedValue;
    return canMove;
}

bool Pawn::canMoveFirstTurn(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool canMove = xAbsDistance == 0 and yAbsDistance <= 2;
    return canMove;
}

void Pawn::setUsedFirstMove() {
    firstMove = false;
}

bool Pawn::isCorrectDirection(int sourceY, int destY) {
    int yDistance = destY - sourceY;
    if (playerId == PlayerID::PLAYER_LIGHT) {
        return yDistance > 0;
    } else if (playerId == PlayerID::PLAYER_DARK) {
        return yDistance < 0;
    }

    return false;
}