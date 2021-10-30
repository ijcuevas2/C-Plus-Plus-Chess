//
// Created by ismael on 9/30/21.
//

#ifndef CHESS_NULLPIECE_H
#define CHESS_NULLPIECE_H

#include "ChessPiece.h"

class NullPiece : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    NullPiece()
            : ChessPiece(PlayerID::NONE, PieceType::NULL_PIECE) { }
};


#endif //CHESS_NULLPIECE_H
