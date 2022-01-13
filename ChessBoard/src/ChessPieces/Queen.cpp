//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Queen.h"
bool Queen::canMove(Coordinates coordinates) {
    bool baseCanMove = ChessPiece::canMove(coordinates);
    if (!baseCanMove) {
        return false;
    }

    bool isHorizontalMovable = canMoveHorizontal(coordinates);
    bool isDiagonalMovable = canMoveDiagonal(coordinates);
    bool isValidPath = isHorizontalMovable || isDiagonalMovable;
    if (isValidPath) {
        bool isPieceBlockingPathValue = isPieceBlockingPath(coordinates);
        return !isPieceBlockingPathValue;
    }

    return false;
}

bool Queen::canMoveDiagonal(Coordinates coordinates) {
    const int xAbsDistance = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    const int yAbsDistance = absoluteDistance(coordinates.sourceY, coordinates.targetY);
    return xAbsDistance == yAbsDistance;
}

bool Queen::canMoveHorizontal(Coordinates coordinates) {
    int xAbsDiff = absoluteDistance(coordinates.sourceX, coordinates.targetX);
    int yAbsDiff = absoluteDistance(coordinates.sourceY, coordinates.targetY);

    bool canMove = (xAbsDiff != 0 && yAbsDiff == 0) or (xAbsDiff == 0 && yAbsDiff != 0);
    return canMove;
}

void Queen::afterPieceMoved(Coordinates coordinates) {

}
