//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Rook.h"
bool Rook::canMove(int sourceX, int sourceY, int destX, int destY) {
    bool baseCanMove = ChessPiece::canMove(sourceX, sourceY, destX, destY);
    if (!baseCanMove) {
        return false;
    }

    int xAbsDiff = absoluteDistance(sourceX, destX);
    int yAbsDiff = absoluteDistance(sourceY, destY);

    // TODO: IMPLEMENT CASTLING
    bool canMove = (xAbsDiff != 0 && yAbsDiff == 0) || (xAbsDiff == 0 && yAbsDiff != 0);
    return canMove;
}
