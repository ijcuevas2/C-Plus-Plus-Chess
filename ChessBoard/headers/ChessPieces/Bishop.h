//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "ChessPiece.h"

class Bishop : public virtual ChessPiece {
public:
    Bishop(PlayerID playerId, QGraphicsItem *parent = nullptr)
            : ChessPiece(playerId, PieceType::BISHOP) {
    }

    bool canMove(Coordinates coordinates);
    void afterPieceMoved(Coordinates coordinates) override;
};


#endif //CHESS_BISHOP_H
