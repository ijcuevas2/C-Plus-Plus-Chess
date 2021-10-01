//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "../headers/ChessPiece.h"
#include <vector>
#include <iostream>
#include <memory>

class Board {
private:
    std::vector<std::vector<ChessPiece*>> board;
    int turn = 0;
    int sNextId = 0;
public:
    const int firstIndex = 0;
    const int lastIndex = 7;
    const int boardSize = 8;

    Board() {
        for (int i = 0; i < boardSize; ++i) {
            this->board.push_back(std::vector<ChessPiece*>(8));
        }
    }

    ~Board() {
        for (std::vector<ChessPiece*> vec : this->board) {
            for (ChessPiece* chessPiecePtr : vec) {
                delete chessPiecePtr;
            }

            vec.clear();
        }

        this->board.clear();
    }

    #include <iostream>
    void setChessPieceBoardIndex(ChessPiece* chessPiece, int posX, int posY) {
        this->board[posY][posX] = chessPiece;
    }

    // TODO: REMOVE THIS FUNCTION
    void printBoard() {
        for (int y = 0; y < this->boardSize; ++y) {
            for (int x = 0; x < this->boardSize; ++x) {
//                std::cout << this->board[y][x]->pieceID << " ";
//                std::cout << (this->board[y][x] == NULL ? "true" : "false") << " ";
                if (y == this->lastIndex && x == this->lastIndex) {
                    std::cout << std::endl;
                    return;
                }
            }

        }
    }

    int getNextId() {
        return ++sNextId;
    }

    void initializeBoard();
    void initializeRooks();
    void initializeKnights();
    void initializeBishops();
    void initializeQueens();
    void initializeKings();
    void initializePawns();
    void initializeNullPieces();
    void incrementTurn();
    int getTurn();
};


#endif //CHESS_BOARD_H
