//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "ChessPiece.h"
#include "../ChessMovementMediator.h"

class Pawn : public ChessPiece {
private:
    bool isFirstMove = true;
    int movedTwoSpacesTurn = -1;
public:
    Pawn(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::PAWN) {
    }

    bool canMove(int sourceX, int sourceY, int destX, int destY);
    bool canMoveFirstTurn(int sourceX, int sourceY, int destX, int destY);
    bool isCorrectDirection(int sourceY, int destY);
    bool canDiagonalCapture(int destX, int destY);
    bool canMoveSingleSpaceForward(int sourceX, int sourceY, int destX, int destY);
    bool isDiagonalMove(int sourceX, int sourceY, int destX, int destY);
    bool canCapture(int sourceX, int sourceY, int destX, int destY);
    bool canEnPassantCapture(int sourceX, int sourceY, int destX, int destY);
    bool getHasMovedTwoSpaces();
    void setUsedFirstMove();
    void setMovedTwoSpacesTurn(int sourceY, int destY);
    int getMovedTwoSpacesTurn();
};


#endif //CHESS_PAWN_H
