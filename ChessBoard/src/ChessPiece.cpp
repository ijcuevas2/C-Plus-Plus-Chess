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

bool ChessPiece::canMove(int sourceX, int sourceY, int destX, int destY) {
    if (sourceX < 0 || sourceX > 7) {
        return false;
    }

    if (sourceY < 0 || sourceY > 7) {
        return false;
    }

    if (destX < 0 || destX > 7) {
        return false;
    }

    if (destY < 0 || destY > 7) {
        return false;
    }

    return true;
}
