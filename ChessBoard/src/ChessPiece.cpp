//
// Created by ismael on 9/29/21.
//

#include "../headers/ChessPieces/ChessPiece.h"
#include <cmath>

int ChessPiece::pieceMovement(int source, int dest) {
    return source - dest;
}

int ChessPiece::absoluteMovement(int source, int dest) {
    return std::abs(pieceMovement(source, dest));
}

PieceType ChessPiece::getPieceType() {
    return this->pieceType;
}
