//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "ChessPiece.h"

class Knight: public virtual ChessPiece {
public:
    Knight(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::KNIGHT) {
    }

    bool canMove(int sourceX, int sourceY, int destX, int destY);
};


#endif //CHESS_KNIGHT_H
