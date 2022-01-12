//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Knight.h"
bool Knight::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);

    bool isValidPath = (xAbsDistance == 2 && yAbsDistance == 1) || (yAbsDistance == 2 && xAbsDistance == 1);
    return isValidPath;
}

void Knight::afterPieceMoved(Coordinates coordinates) {
}