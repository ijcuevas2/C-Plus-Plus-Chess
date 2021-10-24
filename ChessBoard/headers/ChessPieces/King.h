//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "ChessPiece.h"

class King : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    King(PlayerID playerId, QGraphicsItem *parent = nullptr)
            : ChessPiece(playerId, PieceType::KING, parent) {
    }
};


#endif //CHESS_KING_H
