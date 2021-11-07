//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"

class Rook : public virtual ChessPiece {
public:
    Rook(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::ROOK) {
    }

    bool canMove(int sourceX, int sourceY, int destX, int destY);
};


#endif //CHESS_ROOK_H
