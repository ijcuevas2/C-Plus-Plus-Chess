//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Knight.h"
bool Knight::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (not baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool isAbleToMove = (xAbsDistance == 2 and yAbsDistance == 1) or (yAbsDistance == 2 and xAbsDistance == 1);
    return isAbleToMove;
}