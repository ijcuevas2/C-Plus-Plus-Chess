//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/King.h"
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

void King::afterPieceMoved() {
    this->hasMoved = true;
}