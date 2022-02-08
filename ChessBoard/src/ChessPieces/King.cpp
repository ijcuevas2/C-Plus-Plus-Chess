//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/King.h"
#include "../../headers/ChessMovementUtils.h"

bool King::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);
    int maxDistance = std::max(xAbsDistance, yAbsDistance);
    bool canCastle = false;

    if (!hasMoved) {
        std::vector<Rook*> rookPtrList = rooksEligibleForCastling();
        canCastle = rookPtrList.size() > 0 && xAbsDistance == 2 && yAbsDistance == 0;
    }

    bool canMove = maxDistance == 1 || canCastle;
    return canMove;
}

std::vector<Rook*> King::rooksEligibleForCastling() {
    std::vector<Rook*> rookPtrList{};
    if (!hasMoved) {
        // REFACTOR INDICES TO USE CONSTANTS
        int yIndex = ChessMovementUtils::getCurrentTurnPlayerId() == PlayerID::PLAYER_LIGHT ? 7 : 0;
        int xFirstIndex = 0;
        int xLastIndex = 7;
        addRookEligibleForCastling(rookPtrList, xFirstIndex, yIndex);
        addRookEligibleForCastling(rookPtrList, xLastIndex, yIndex);
    }

    return rookPtrList;
}

void King::addRookEligibleForCastling(std::vector<Rook*> & rookPtrList, int xIndex, int yIndex) {
    ChessPiece* chessPiece = ChessMovementUtils::getChessPieceAtIndex(xIndex, yIndex);
    if (chessPiece->getPieceType() == PieceType::ROOK) {
        Rook* rookPtr = dynamic_cast<Rook*>(chessPiece);
        if (!rookPtr->HasMoved()) {
            addRookEligibleForCastlingHelper(rookPtr, rookPtrList, xIndex, yIndex);
        }
    }
}

void King::addRookEligibleForCastlingHelper(Rook* rookPtr, std::vector<Rook*> & rookPtrList, int xIndex, int yIndex) {
    int currIndex = xIndex;
    int direction = xIndex == 0 ? 1 : -1;
    currIndex += direction;
    const int KING_INDEX = 4;
    while (currIndex != KING_INDEX) {
        bool isOccupied = ChessMovementUtils::isBoardIndexOccupied(currIndex, yIndex);
        if (isOccupied) {
            return;
        }

        currIndex += direction;
    }

    rookPtrList.push_back(rookPtr);
}

// TODO: IMPLEMENT CASTLING
void King::afterPieceMoved(Coordinates coordinates) {
    this->hasMoved = true;
}

bool King::HasMoved() const {
    return hasMoved;
}

bool King::IsInCheck() const {
    return isInCheck;
}
