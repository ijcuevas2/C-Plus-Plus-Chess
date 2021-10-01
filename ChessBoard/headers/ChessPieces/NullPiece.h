//
// Created by ismael on 9/30/21.
//

#ifndef CHESS_NULLPIECE_H
#define CHESS_NULLPIECE_H

#include "../ChessPiece.h"

class NullPiece : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    NullPiece()
            : ChessPiece(-1, PlayerID::NONE) { }
protected:
    int pieceID = -1;
    PieceType pieceType = PieceType::NULL_PIECE;
    const PlayerID affiliation = PlayerID::NONE;
};


#endif //CHESS_NULLPIECE_H
