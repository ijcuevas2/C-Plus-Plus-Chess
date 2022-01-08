//
// Created by ismael on 9/30/21.
//

#ifndef CHESS_EMPTYPIECE_H
#define CHESS_EMPTYPIECE_H

#include "ChessPiece.h"

class EmptyPiece : public virtual ChessPiece {
public:
    EmptyPiece()
            : ChessPiece(PlayerID::NONE, PieceType::EMPTY_PIECE) { }
    bool canMove(Coordinates coordinates);
    void afterPieceMoved(Coordinates coordinates) override;
};


#endif //CHESS_EMPTYPIECE_H
