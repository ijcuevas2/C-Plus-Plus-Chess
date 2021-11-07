//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "ChessPiece.h"

class Queen: public virtual ChessPiece {
public:
    Queen(PlayerID playerId, QGraphicsItem *parent = nullptr)
            : ChessPiece(playerId, PieceType::QUEEN) {
    }

    bool canMove(int sourceX, int sourceY, int destX, int destY);
};


#endif //CHESS_QUEEN_H
