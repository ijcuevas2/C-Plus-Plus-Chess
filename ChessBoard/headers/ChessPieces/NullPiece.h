//
// Created by ismael on 9/30/21.
//

#ifndef CHESS_NULLPIECE_H
#define CHESS_NULLPIECE_H

#include "ChessPiece.h"

class NullPiece : public virtual ChessPiece {
public:
    NullPiece()
            : ChessPiece(PlayerID::NONE, PieceType::NULL_PIECE) { }
    bool canMove(int sourceX, int sourceY, int destX, int destY);
};


#endif //CHESS_NULLPIECE_H
