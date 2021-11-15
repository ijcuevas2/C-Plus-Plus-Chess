//
// Created by ismael on 11/7/21.
//

#ifndef CHESS_CHESSMOVEMENTMEDIATOR_H
#define CHESS_CHESSMOVEMENTMEDIATOR_H

#include <vector>
#include "BoardSpace.h"
#include "./ChessPieces/NullPiece.h"
#include <QLabel>

class ChessMovementMediator {
private:
    inline static int currentTurn = 1;
    inline static std::vector<BoardSpace*> boardSpaceList;
    inline static QLabel* qLabelPtr;
    static void setBoardSpaceBackground(BoardSpace* boardSpace);
    static void incrementTurn();

    static bool isTurnPlayerPiece(ChessPiece* chessPiece);
    static void tryMovingChessPiece();
    static void moveChessPiece();
    static const bool canMove(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace);
    static void clearBoardSpace();
public:
    static void addBoardSpace(BoardSpace* boardSpace);
    static void setLabelPtr(QLabel* qLabel);

    static bool isFirstTurn();
};


#endif //CHESS_CHESSMOVEMENTMEDIATOR_H
