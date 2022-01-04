//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Bishop.h"
bool Bishop::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    const int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.destX);
    const int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.destY);
    bool isValidPath = xAbsDistance == yAbsDistance;
    if (isValidPath) {
        bool isPieceBlockingPathValue = isPieceBlockingPath(coordinates);
        return !isPieceBlockingPathValue;
    }

    return false;
}

void Bishop::afterPieceMoved(Coordinates coordinates) {

}