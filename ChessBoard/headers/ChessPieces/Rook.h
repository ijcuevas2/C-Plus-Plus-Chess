//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"

class Rook : public ChessPiece {
private:
     bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    Rook(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::ROOK, parent) {
    }
};


#endif //CHESS_ROOK_H
