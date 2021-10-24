//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "ChessPiece.h"

class Knight: public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    Knight(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::KNIGHT, parent) {
    }
};


#endif //CHESS_KNIGHT_H
