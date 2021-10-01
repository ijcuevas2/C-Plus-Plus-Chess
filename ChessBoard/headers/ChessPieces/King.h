//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "../ChessPiece.h"

class King : public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    King(int pieceId, PlayerID affiliation)
            : ChessPiece(pieceId, affiliation) { }
protected:
    int pieceID;
    PieceType pieceType = PieceType::KING;
    PlayerID affiliation;
};


#endif //CHESS_KING_H
