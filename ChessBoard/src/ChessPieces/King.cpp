//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/King.h"
bool King::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);
    int maxDistance = std::max(xAbsDistance, yAbsDistance);
    bool canMove = maxDistance == 1;
    return canMove;
}

void King::afterPieceMoved() {
    this->hasMoved = true;
}