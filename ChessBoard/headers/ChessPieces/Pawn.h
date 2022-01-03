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
    bool isEnPassantEligible = false;
public:
    Pawn(PlayerID playerId, QGraphicsItem *parent = nullptr)
        : ChessPiece(playerId, PieceType::PAWN) {
    }

    bool canMove(Coordinates coordinates);
    bool isCorrectDirection(Coordinates coordinates);
    bool canMoveFirstTurn(Coordinates coordinates);
    bool canDiagonalCapture(Coordinates coordinates);
    bool canMoveSingleSpaceForward(Coordinates coordinates);
    bool isDiagonalMove(Coordinates coordinates);
    bool canCapture(Coordinates coordinates);
    bool canEnPassantCapture(Coordinates coordinates);
    void setUsedFirstMove();
    void setMovedTwoSpacesTurn(Coordinates coordinates);
    void afterPieceMoved() override;
    int getMovedTwoSpacesTurn();
};


#endif //CHESS_PAWN_H
