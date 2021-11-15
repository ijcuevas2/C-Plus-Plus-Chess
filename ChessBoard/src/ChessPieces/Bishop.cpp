//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Bishop.h"
bool Bishop::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (not baseCanMove) {
        return false;
    }

    const int xAbsDistance = absoluteDistance(sourceX, destX);
    const int yAbsDistance = absoluteDistance(sourceY, destY);
    return xAbsDistance == yAbsDistance;
}
