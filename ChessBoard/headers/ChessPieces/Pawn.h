//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "../ChessPiece.h"

class Pawn : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    Pawn(int pieceId, PlayerID affiliation)
        : ChessPiece(pieceId, affiliation) { }
protected:
    int pieceID;
    PieceType pieceType = PieceType::PAWN;
    PlayerID affiliation;
};


#endif //CHESS_PAWN_H
