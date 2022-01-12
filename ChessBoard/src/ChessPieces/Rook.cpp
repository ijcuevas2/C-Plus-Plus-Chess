//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Rook.h"
bool Rook::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDiff = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDiff = absoluteDistance(coordinates.sourceY, coordinates.targetY);

    bool isValidPath = (xAbsDiff != 0 && yAbsDiff == 0) || (xAbsDiff == 0 && yAbsDiff != 0);
    if (isValidPath) {
        bool isPieceBlockingPathValue = isPieceBlockingPath(coordinates);
        return !isPieceBlockingPathValue;
    }

    return false;
}

// TODO: IMPLEMENT CASTLING
void Rook::afterPieceMoved(Coordinates coordinates) {
    this->hasMoved = true;
}

bool Rook::HasMoved() const {
    return hasMoved;
}
