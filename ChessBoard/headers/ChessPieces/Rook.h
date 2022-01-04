//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "ChessPiece.h"

class Rook : public virtual ChessPiece {
private:
    bool hasMoved;
public:
    Rook(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::ROOK) {
    }

    bool canMove(Coordinates coordinates);
    void afterPieceMoved(Coordinates coordinates) override;
};


#endif //CHESS_ROOK_H
