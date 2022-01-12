//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Pawn.h"

bool Pawn::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    bool isCorrectDirectionValue = isCorrectDirection(coordinates);
    if (!isCorrectDirectionValue) {
        return false;
    }

    // TODO: IMPLEMENT EN PASSANT
    if (isFirstMove) {
        bool canMove = canMoveFirstTurn(coordinates);
        return canMove;
    } else {
        bool canCaptureValue = canCapture(coordinates);
        bool canMoveSingleSpaceValue = canMoveSingleSpaceForward(coordinates);
        return canCaptureValue || canMoveSingleSpaceValue;
    }
}

bool Pawn::canCapture(Coordinates coordinates) {
    bool isDiagonalMoveValue = isDiagonalMove(coordinates);
    if (isDiagonalMoveValue) {
        bool canDiagonalCaptureValue = canDiagonalCapture(coordinates);
        if (canDiagonalCaptureValue) {
            return true;
        }

        bool canEnPassantCaptureValue = canEnPassantCapture(coordinates);
        if (canEnPassantCaptureValue) {
            return true;
        }
    }

    return false;
}

bool Pawn::canEnPassantCapture(Coordinates coordinates) {
    bool isIndexOccupiedValue = ChessMovementUtils::isBoardIndexOccupied(coordinates.targetX, coordinates.targetY);
    if (!isIndexOccupiedValue) {
        int targetPieceX = coordinates.targetX;
        int targetPieceY = coordinates.sourceY;
        int enPassantTurn = ChessMovementUtils::getMovedTwoSpacesTurn(targetPieceX, targetPieceY) + 1;
        bool canEnPassantCaptureResult = enPassantTurn == ChessMovementUtils::getCurrentTurn();
        return canEnPassantCaptureResult;
    }

    return false;
}

bool Pawn::canDiagonalCapture(Coordinates coordinates) {
    bool isIndexOccupiedResult = ChessMovementUtils::isBoardIndexOccupied(coordinates.targetX, coordinates.targetY);
    return isIndexOccupiedResult;
}

bool Pawn::isDiagonalMove(Coordinates coordinates) {
    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);
    bool isDiagonalMoveResult = xAbsDistance == 1 && yAbsDistance == 1;
    return isDiagonalMoveResult;
}

// TODO: Check if space is not occupied
bool Pawn::canMoveSingleSpaceForward(Coordinates coordinates) {
    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);

    bool isTargetOccupiedValue = ChessMovementUtils::isBoardIndexOccupied(coordinates.targetX, coordinates.targetY);

    bool canMove = xAbsDistance == 0 && yAbsDistance < 2 && !isTargetOccupiedValue;
    return canMove;
}

bool Pawn::canMoveFirstTurn(Coordinates coordinates) {
    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);

    bool canMove = xAbsDistance == 0 && yAbsDistance <= 2;
    return canMove;
}

void Pawn::setUsedFirstMove() {
    this->isFirstMove = false;
}

void Pawn::setMovedTwoSpacesTurn(Coordinates coordinates) {
    int absoluteDistanceValue = absoluteDistance(coordinates.sourceY, coordinates.targetY);
    bool movedTwoSpacesResult = absoluteDistanceValue == 2;
    if (movedTwoSpacesResult) {
        this->movedTwoSpacesTurn = ChessMovementUtils::getCurrentTurn();
    }
}

int Pawn::getMovedTwoSpacesTurn() {
    return this->movedTwoSpacesTurn;
}

bool Pawn::isCorrectDirection(Coordinates coordinates) {
    int yDistance = coordinates.targetY - coordinates.sourceY;
    if (playerId == PlayerID::PLAYER_LIGHT) {
        return yDistance < 0;
    } else if (playerId == PlayerID::PLAYER_DARK) {
        return yDistance > 0;
    }

    return false;
}

void Pawn::afterPieceMoved(Coordinates coordinates) {
    if (isFirstMove) {
        setUsedFirstMove();
        setMovedTwoSpacesTurn(coordinates);
    }

    ChessMovementUtils::handlePawnPromotion(coordinates);
}