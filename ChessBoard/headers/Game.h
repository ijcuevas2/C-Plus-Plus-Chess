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
#include <QGraphicsItemGroup>

class Game {
private:
    std::vector<std::vector<BoardSpace*>> board;
public:
    // TODO: MAKE THESE FIELDS PRIVATE or REFACTOR THEM
    const int firstIndex = 0;
    const int lastIndex = 7;
    const int boardSize = 8;

    Game();
    ~Game();

    ChessPiece* getChessPieceAtBoardIndex(int xIndex, int yIndex);
    BoardSpace* getBoardSpaceAtIndex(int xIndex, int yIndex);
    void setBoardSpaceAtIndex(ChessPiece* chessPiece, int xIndex, int yIndex);
    void setChessPieceAtBoardIndex(ChessPiece* chessPiece, int xIndex, int yIndex);
    std::vector<std::vector<BoardSpace*>> getBoard();
    int getBoardSize();
    void initializeBoard();
    bool isValidEncoding(std::vector<std::vector<std::string>> chessBoard);
    void parseChessBoard(std::vector<std::vector<std::string>> chessBoard);
    PlayerID parsePlayerId(std::string pieceEncoding);
    PieceType parsePieceType(std::string pieceEncoding);
    ChessPiece* initChessPiece(std::string pieceEncoding);
};


#endif //CHESS_GAME_H
