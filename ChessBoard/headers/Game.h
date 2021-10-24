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

class Game {
private:
    std::vector<std::vector<BoardSpace*>> board;
    int turn = 0;
public:
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

    void setChessPieceBoardIndex(ChessPiece* chessPiece, int posX, int posY) {
        Point chessPoint(posX, posY);
        BoardSpace* boardSpace = new BoardSpace(chessPiece, chessPoint);
        this->board[posY][posX] = boardSpace;
    }

    std::vector<std::vector<BoardSpace*>> getBoard() {
        return this->board;
    }

    void printBoard() {
        std::map<PieceType, std::string> imageResourceMap = {{PieceType::ROOK, "rook"},
                                                             {PieceType::KNIGHT, "knight"},
                                                             {PieceType::BISHOP, "bishop"},
                                                             {PieceType::QUEEN, "queen"},
                                                             {PieceType::KING, "king"},
                                                             {PieceType::PAWN, "pawn"},
                                                             {PieceType::NULL_PIECE, ""}};
        for (int y = 0; y < this->boardSize; ++y) {
            for (int x = 0; x < this->boardSize; ++x) {
                ChessPiece* chessPiece = this->board[x][y]->getChessPiece();
                PieceType pieceType = chessPiece->getPieceType();
                std::string pieceTypeStr = imageResourceMap[pieceType];
                std::cout << pieceTypeStr << std::endl;
            }
        }
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


#endif //CHESS_GAME_H
