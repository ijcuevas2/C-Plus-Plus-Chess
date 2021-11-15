//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Queen.h"
bool Queen::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (not baseCanMove) {
        return false;
    }

    bool isHorizontalMovable = canMoveHorizontal(sourceX, sourceX, destX, destY);
    bool isDiagonalMovable = canMoveDiagonal(sourceX, sourceX, destX, destY);
    return isHorizontalMovable or isDiagonalMovable;
}

bool Queen::canMoveDiagonal(int sourceX, int sourceY, int destX, int destY) {
    const int xAbsDistance = absoluteDistance(sourceX, destX);
    const int yAbsDistance = absoluteDistance(sourceY, destY);
    return xAbsDistance == yAbsDistance;
}

bool Queen::canMoveHorizontal(int sourceX, int sourceY, int destX, int destY) {
    int xAbsDiff = absoluteDistance(sourceX, destX);
    int yAbsDiff = absoluteDistance(sourceY, destY);

    bool canMove = (xAbsDiff not_eq 0 and yAbsDiff == 0) or (xAbsDiff == 0 and yAbsDiff not_eq 0);
    return canMove;
}
