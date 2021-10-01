//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "../ChessPiece.h"

class Bishop : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    Bishop(int pieceId, PlayerID affiliation)
            : ChessPiece(pieceId, affiliation) { }
protected:
    int pieceID;
    PieceType pieceType = PieceType::BISHOP;
    PlayerID affiliation;
};


#endif //CHESS_BISHOP_H
