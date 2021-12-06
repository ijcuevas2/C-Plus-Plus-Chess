//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "ChessPieces/ChessPiece.h"
#include <vector>
#include <iostream>
#include <memory>
#include "./BoardSpace.h"
#include "./Point.h"
#include <QGraphicsItemGroup>

class Game {
private:
    std::vector<std::vector<BoardSpace*>> board;
public:
    // TODO: MAKE THESE FIELDS PRIVATE
    const int firstIndex = 0;
    const int lastIndex = 7;
    const int boardSize = 8;

    Game() {
        for (int i = 0; i < boardSize; ++i) {
            this->board.push_back(std::vector<BoardSpace*>(8));
        }

        initializeBoard();
    }

    ~Game() {
        for (std::vector<BoardSpace*> vec : this->board) {
            for (BoardSpace* pBoardSpace : vec) {
                delete pBoardSpace;
            }

            vec.clear();
        }

        this->board.clear();
    }

    ChessPiece* getChessPieceAtBoardIndex(int xIndex, int yIndex);
    BoardSpace* getBoardSpaceAtIndex(int xIndex, int yIndex);
    void setBoardSpaceAtIndex(ChessPiece* chessPiece, int xIndex, int yIndex);
    void setChessPieceAtBoardIndex(ChessPiece* chessPiece, int xIndex, int yIndex);
    std::vector<std::vector<BoardSpace*>> getBoard();
    int getBoardSize();
    void initializeBoard();
    void initializeRooks();
    void initializeKnights();
    void initializeBishops();
    void initializeQueens();
    void initializeKings();
    void initializePawns();
    void initializeNullPieces();
};


#endif //CHESS_GAME_H
