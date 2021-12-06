//
// Created by ismael on 9/29/21.
//

#include "../headers/Game.h"
#include "../headers/ChessPieces/Rook.h"
#include "../headers/ChessPieces/Knight.h"
#include "../headers/ChessPieces/Bishop.h"
#include "../headers/ChessPieces/Queen.h"
#include "../headers/ChessPieces/King.h"
#include "../headers/ChessPieces/Pawn.h"
#include "../headers/ChessPieces/NullPiece.h"

void Game::initializeRooks() {
    setBoardSpaceAtIndex(new Rook(PlayerID::PLAYER_DARK), firstIndex, firstIndex);
    setBoardSpaceAtIndex(new Rook(PlayerID::PLAYER_DARK), lastIndex, firstIndex);
    setBoardSpaceAtIndex(new Rook(PlayerID::PLAYER_LIGHT), firstIndex, lastIndex);
    setBoardSpaceAtIndex(new Rook(PlayerID::PLAYER_LIGHT), lastIndex, lastIndex);
}

void Game::initializeKnights() {
    int offset = 1;
    setBoardSpaceAtIndex(new Knight(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setBoardSpaceAtIndex(new Knight(PlayerID::PLAYER_DARK), lastIndex - offset, firstIndex);
    setBoardSpaceAtIndex(new Knight(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
    setBoardSpaceAtIndex(new Knight(PlayerID::PLAYER_LIGHT), lastIndex - offset, lastIndex);
}

void Game::initializeBishops() {
    int offset = 2;
    setBoardSpaceAtIndex(new Bishop(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setBoardSpaceAtIndex(new Bishop(PlayerID::PLAYER_DARK), lastIndex - offset, firstIndex);
    setBoardSpaceAtIndex(new Bishop(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
    setBoardSpaceAtIndex(new Bishop(PlayerID::PLAYER_LIGHT), lastIndex - offset, lastIndex);
}

void Game::initializeQueens() {
    int offset = 3;
    setBoardSpaceAtIndex(new Queen(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setBoardSpaceAtIndex(new Queen(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
}

void Game::initializeKings() {
    int offset = 4;
    setBoardSpaceAtIndex(new King(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setBoardSpaceAtIndex(new King(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
}

void Game::initializePawns() {
    for (int i = 0; i < Game::boardSize; ++i) {
        setBoardSpaceAtIndex(new Pawn(PlayerID::PLAYER_DARK), i, firstIndex + 1);
        setBoardSpaceAtIndex(new Pawn(PlayerID::PLAYER_LIGHT), i, lastIndex - 1);
    }
}

void Game::initializeNullPieces() { for (int y = firstIndex + 2; y < Game::boardSize - 2; ++y) {
        for (int x = firstIndex; x < Game::boardSize; ++x) {
            setBoardSpaceAtIndex(new NullPiece(), x, y);
        }
    }
}

ChessPiece* Game::getChessPieceAtBoardIndex(int xIndex, int yIndex) {
    if (xIndex < 0 || xIndex > 7 || yIndex < 0 || yIndex > 7) {
        return NULL;
    }

    if ((!board.empty()) && (!board[yIndex].empty()) && board[yIndex][xIndex] != NULL) {
        return this->board[yIndex][xIndex]->getChessPiece();
    }

    return NULL;
}

std::vector<std::vector<BoardSpace*>> Game::getBoard() {
    return this->board;
}

int Game::getBoardSize() {
    return this->boardSize;
}

// TODO: ADD NULL CHECKS FOR INDICES
void Game::setChessPieceAtBoardIndex(ChessPiece* chessPiece, int xIndex, int yIndex) {
    if (xIndex < 0 || xIndex > 7 || yIndex < 0 || yIndex > 7) {
        return;
    }

    BoardSpace* boardSpace = this->board[yIndex][xIndex];
    if (boardSpace != NULL) {
        ChessPiece* currentChessPiece = boardSpace->getChessPiece();
        if (currentChessPiece != NULL) {
            delete currentChessPiece;
        }

        boardSpace->setChessPiece(chessPiece);
    }
}

BoardSpace* Game::getBoardSpaceAtIndex(int xIndex, int yIndex) {
    return NULL;
}

void Game::setBoardSpaceAtIndex(ChessPiece* chessPiece, int xIndex, int yIndex) {
    BoardSpace* boardSpace = new BoardSpace(chessPiece, xIndex, yIndex);
    this->board[yIndex][xIndex] = boardSpace;
}


void Game::initializeBoard() {
    this->initializeRooks();
    this->initializeKnights();
    this->initializeBishops();
    this->initializeQueens();
    this->initializeKings();
    this->initializePawns();
    this->initializeNullPieces();
}
