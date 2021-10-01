//
// Created by ismael on 9/29/21.
//

#include "../headers/ChessPiece.h"
#include <cmath>

bool ChessPiece::samePiece(int source_x, int source_y, int dest_x, int dest_y){
    return false;
};

int ChessPiece::pieceDisplacement(int source, int dest) {
    return source - dest;
}

int ChessPiece::absolutePieceDisplacement(int source, int dest) {
    return std::abs(pieceDisplacement(source, dest));
}

PlayerID ChessPiece::getAffiliation() {
    return this->affiliation;
}


bool ChessPiece::reachedDestination(int source_x, int source_y, int dest_x, int dest_y) {
    return source_x == dest_x && source_y == dest_y;
}
