//
// Created by ismael on 9/29/21.
//

#include "../headers/ChessPieces/ChessPiece.h"
#include <cmath>

int ChessPiece::pieceMovement(int source, int dest) {
    return source - dest;
}

int ChessPiece::absoluteDistance(int source, int dest) {
    return std::abs(pieceMovement(source, dest));
}

PieceType ChessPiece::getPieceType() {
    return this->pieceType;
}

PlayerID ChessPiece::getPlayerId() {
    return playerId;
}

bool ChessPiece::canMove(Coordinates coordinates) {
    if (coordinates.sourceX < 0 || coordinates.sourceX > 7) {
        return false;
    }

    if (coordinates.sourceY < 0 || coordinates.sourceY > 7) {
        return false;
    }

    if (coordinates.destX < 0 || coordinates.destX > 7) {
        return false;
    }

    if (coordinates.destY < 0 || coordinates.destY > 7) {
        return false;
    }

    return true;
}
