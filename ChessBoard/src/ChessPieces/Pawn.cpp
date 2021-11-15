//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Pawn.h"

bool Pawn::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (not baseCanMove) {
        return false;
    }

    bool isCorrectDirectionBool = isCorrectDirection(sourceX, sourceY, destX, destY);
    if (not isCorrectDirectionBool) {
        return false;
    }

    bool isFirstTurnBool = ChessMovementMediator::isFirstTurn();

    // TODO: IMPLEMENT EN PASSANT
    if (isFirstTurnBool) {
        bool canMove = canMoveFirstTurn(sourceX, sourceY, destX, destY);
        return canMove;
    } else {
    }

    return true;
}

bool Pawn::canDiagonalCapture(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);
    if (xAbsDistance == 1 and xAbsDistance == yAbsDistance) {
    }

    return false;
}

// TODO: Check if space is not occupied
bool Pawn::canMoveSingleSpace(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool canMove = xAbsDistance == 0 && yAbsDistance < 2;
    return canMove;
}

bool Pawn::canMoveFirstTurn(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool canMove = xAbsDistance == 0 and yAbsDistance <= 2;
    return canMove;
}

bool Pawn::isCorrectDirection(int sourceX, int sourceY, int destX, int destY) {
    int yDistance = destY - sourceY;
    if (playerId == PlayerID::PLAYER_LIGHT) {
        return yDistance > 0;
    } else if (playerId == PlayerID::PLAYER_DARK) {
        return yDistance < 0;
    }

    return false;
}