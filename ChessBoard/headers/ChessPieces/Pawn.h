//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::PAWN) {
    }

    bool canMove(int sourceX, int sourceY, int destX, int destY);
};


#endif //CHESS_PAWN_H
