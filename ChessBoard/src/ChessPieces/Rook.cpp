//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Rook.h"
bool Rook::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDiff = absoluteDistance(coordinates.sourceX, coordinates.destX);
    int yAbsDiff = absoluteDistance(coordinates.sourceY, coordinates.destY);

    bool canMove = (xAbsDiff != 0 && yAbsDiff == 0) || (xAbsDiff == 0 && yAbsDiff != 0);
    return canMove;
}

void Rook::afterPieceMoved() {
    this->hasMoved = true;
}
