//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "ChessPiece.h"

class King : public virtual ChessPiece {
private:
    bool hasMoved;
public:
    King(PlayerID playerId, QGraphicsItem *parent = nullptr)
            : ChessPiece(playerId, PieceType::KING) {
    }

    bool canMove(Coordinates coordinates);
    void afterPieceMoved() override;
};


#endif //CHESS_KING_H
