//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/King.h"
#include "../../headers/ChessMovementMediator.h"

bool King::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.destX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.destY);
    int maxDistance = std::max(xAbsDistance, yAbsDistance);

    bool canMove = maxDistance == 1;
    return canMove;
}

std::vector<Rook*> King::rooksEligibleForCastling() {
    std::vector<Rook*> rookPtrList{};
    if (!hasMoved) {
        int yIndex = ChessMovementMediator::getCurrentTurnPlayerId() == PlayerID::PLAYER_LIGHT ? 7 : 0;
        int xFirstIndex = 0;
        int xLastIndex = 7;

    }
    return rookPtrList;
}

// TODO: IMPLEMENT CASTLING
void King::afterPieceMoved(Coordinates coordinates) {
    this->hasMoved = true;
}