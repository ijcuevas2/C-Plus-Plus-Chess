//
// Created by ismael on 11/7/21.
//

#ifndef CHESS_CHESSMOVEMENTUTILS_H
#define CHESS_CHESSMOVEMENTUTILS_H

#include <vector>
#include "BoardSpace.h"
#include "./ChessPieces/EmptyPiece.h"
#include "Game.h"
#include <QLabel>

// TODO: Check if name could be changed
class ChessMovementUtils {
private:
    inline static int currentTurn = 1;
    inline static std::vector<BoardSpace*> boardSpaceList;
    inline static QLabel* turnLabelPtr;
    inline static Game* gamePtr;
    static void setBoardSpaceBackground(BoardSpace* boardSpace);
    static void incrementTurn();

    static bool isTurnPlayerPiece(ChessPiece* chessPiece);
    static void tryMovingChessPiece();
    static void moveChessPiece();
    static const bool canMove(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace);

    static void handleEnPassantCapture(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace);
public:
    static void setChessPieceAtIndex(ChessPiece* chessPiece, int targetX, int targetY);
    static ChessPiece* getChessPieceAtIndex(int xIndex, int yIndex);
    static BoardSpace* getBoardSpaceAtIndex(int xIndex, int yIndex);
    static bool haveSamePlayerId(Coordinates coordinates);
    static void showHints(BoardSpace* boardSpace);
    static void hideHints();
    static void addBoardSpace(BoardSpace* boardSpace);
    static void setLabelPtr(QLabel* qLabel);
    static void setGamePtr(Game* gamePtr);
    static bool isBoardIndexOccupied(int targetX, int targetY);
    static int getCurrentTurn();
    static int getMovedTwoSpacesTurn(int targetX, int targetY);

    static void clearBoardSpaceList();

    static PlayerID getCurrentTurnPlayerId();
};


#endif //CHESS_CHESSMOVEMENTUTILS_H
