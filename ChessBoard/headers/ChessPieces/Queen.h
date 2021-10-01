//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "../ChessPiece.h"

class Queen: public ChessPiece {
private:
    bool movement(int source_x, int source_y, int dest_x, int dest_y);
public:
    Queen(int pieceId, PlayerID affiliation)
            : ChessPiece(pieceId, affiliation) { }
protected:
    int pieceID;
    PieceType pieceType = PieceType::QUEEN;
    PlayerID affiliation;
};


#endif //CHESS_QUEEN_H
