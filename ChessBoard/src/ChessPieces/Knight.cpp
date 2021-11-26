//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Knight.h"
bool Knight::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDistance = absoluteDistance(sourceX, destX);
    int yAbsDistance = absoluteDistance(sourceY, destY);

    bool isAbleToMove = (xAbsDistance == 2 && yAbsDistance == 1) || (yAbsDistance == 2 && xAbsDistance == 1);
    return isAbleToMove;
}