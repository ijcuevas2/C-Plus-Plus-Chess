//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include "../enums/PieceType.h"
#include "../enums/Player.h"

class ChessPiece {
private:
    virtual bool movement(int source_x, int source_y, int dest_x, int dest_y) = 0;
public:
    ChessPiece(int pieceID, PlayerID affiliation) {
        this->pieceID = pieceID;
        this->affiliation = affiliation;
    }
    ~ChessPiece();
    bool samePiece(int source_x, int source_y, int dest_x, int dest_y);
    bool reachedDestination(int source_x, int source_y, int dest_x, int dest_y);
    int pieceDisplacement(int source, int dest);
    int absolutePieceDisplacement(int source, int dest);
    PlayerID getAffiliation();
protected:
    int pieceID;
    PieceType pieceType;
    PlayerID affiliation;
};

#endif //CHESS_CHESSPIECE_H
