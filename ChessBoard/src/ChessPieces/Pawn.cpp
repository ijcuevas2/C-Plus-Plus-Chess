//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Pawn.h"

bool Pawn::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (!baseCanMove) {
        return false;
    }

    bool isCorrectDirectionValue = isCorrectDirection(sourceY, destY);
    if (!isCorrectDirectionValue) {
        return false;
    }

    // TODO: IMPLEMENT EN PASSANT
    if (isFirstMove) {
        bool canMove = canMoveFirstTurn(sourceX, sourceY, destX, destY);

        if (canMove) {
            setUsedFirstMove();
            setMovedTwoSpacesTurn(sourceY, destY);
        }

        return canMove;
    } else {
        bool canCaptureValue = canCapture(sourceX, sourceY, destX, destY);
        bool canMoveSingleSpaceValue = canMoveSingleSpaceForward(sourceX, sourceY, destX, destY);
        return canCaptureValue || canMoveSingleSpaceValue;
    }
}

bool Pawn::canCapture(int sourceX, int sourceY, int destX, int destY) {
    bool isDiagonalMoveValue = isDiagonalMove(sourceX, sourceY, destX, destY);
    if (isDiagonalMoveValue) {
        bool canDiagonalCaptureValue = canDiagonalCapture(destX, destY);
        if (canDiagonalCaptureValue) {
            return true;
        }

        bool canEnPassantCaptureValue = canEnPassantCapture(sourceX, sourceY, destX, destY);
        if (canEnPassantCaptureValue) {
            return true;
        }
    }

    return false;
}

bool Pawn::canEnPassantCapture(int sourceX, int sourceY, int destX, int destY) {
    bool isIndexOccupiedValue = ChessMovementMediator::isBoardIndexOccupied(destX, destY);
    if (!isIndexOccupiedValue) {
        int targetPieceX = destX;
        int targetPieceY = sourceY;
        int enPassantTurn = ChessMovementMediator::getMovedTwoSpacesTurn(targetPieceX, targetPieceY) + 1;
        bool canEnPassantCaptureResult = enPassantTurn == ChessMovementMediator::getCurrentTurn();
        return canEnPassantCaptureResult;
    }

    return false;
}

bool Pawn::canDiagonalCapture(int destX, int destY) {
    bool isIndexOccupiedResult = ChessMovementMediator::isBoardIndexOccupied(destX, destY);
    return isIndexOccupiedResult;
}

bool Pawn::isDiagonalMove(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);
    bool isDiagonalMoveResult = xAbsDistance == 1 && yAbsDistance == 1;
    return isDiagonalMoveResult;
}

// TODO: Check if space is not occupied
bool Pawn::canMoveSingleSpaceForward(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool isTargetOccupiedValue = ChessMovementMediator::isBoardIndexOccupied(destX, destY);

    bool canMove = xAbsDistance == 0 && yAbsDistance < 2 && !isTargetOccupiedValue;
    return canMove;
}

bool Pawn::canMoveFirstTurn(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool canMove = xAbsDistance == 0 && yAbsDistance <= 2;
    return canMove;
}

void Pawn::setUsedFirstMove() {
    this->isFirstMove = false;
}

void Pawn::setMovedTwoSpacesTurn(int sourceY, int destY) {
    int absoluteDistanceValue = absoluteDistance(sourceY, destY);
    bool movedTwoSpacesResult = absoluteDistanceValue == 2;
    if (movedTwoSpacesResult) {
        this->movedTwoSpacesTurn = ChessMovementMediator::getCurrentTurn();
    }
}

int Pawn::getMovedTwoSpacesTurn() {
    return this->movedTwoSpacesTurn;
}

bool Pawn::isCorrectDirection(int sourceY, int destY) {
    int yDistance = destY - sourceY;
    if (playerId == PlayerID::PLAYER_LIGHT) {
        return yDistance < 0;
    } else if (playerId == PlayerID::PLAYER_DARK) {
        return yDistance > 0;
    }

    return false;
}
