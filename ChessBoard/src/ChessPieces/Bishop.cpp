//
// Created by ismael on 9/29/21.
//

#include "../../headers/ChessPieces/Bishop.h"
bool Bishop::canMove(int source_x, int source_y, int dest_x, int dest_y) {
    const int absMovementX = absoluteMovement(source_x, dest_x);
    const int absMovementY = absoluteMovement(source_y, dest_y);
    return absMovementX == absMovementY;
}
