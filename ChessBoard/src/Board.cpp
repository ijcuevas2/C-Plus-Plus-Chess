//
// Created by ismael on 9/29/21.
//

#include "../headers/Board.h"
#include "../headers/ChessPieces/Rook.h"
#include "../headers/ChessPieces/Knight.h"
#include "../headers/ChessPieces/Bishop.h"
#include "../headers/ChessPieces/Queen.h"
#include "../headers/ChessPieces/King.h"
#include "../headers/ChessPieces/Pawn.h"
#include "../enums/Player.h"
#include "../headers/ChessPieces/NullPiece.h"

void Board::incrementTurn() {
    turn++;
}

int Board::getTurn() {
    return turn;
}

void Board::initializeRooks() {
    setChessPieceBoardIndex(new Rook(getNextId(), PlayerID::PLAYER_1), firstIndex, firstIndex);
    setChessPieceBoardIndex(new Rook(getNextId(), PlayerID::PLAYER_1), lastIndex, firstIndex);
    setChessPieceBoardIndex(new Rook(getNextId(), PlayerID::PLAYER_2), firstIndex, lastIndex);
    setChessPieceBoardIndex(new Rook(getNextId(), PlayerID::PLAYER_2), lastIndex, lastIndex);
}

void Board::initializeKnights() {
    int offset = 1;
    setChessPieceBoardIndex(new Knight(getNextId(), PlayerID::PLAYER_1), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Knight(getNextId(), PlayerID::PLAYER_1), lastIndex - offset, firstIndex);
    setChessPieceBoardIndex(new Knight(getNextId(), PlayerID::PLAYER_2), firstIndex + offset, lastIndex);
    setChessPieceBoardIndex(new Knight(getNextId(), PlayerID::PLAYER_2), lastIndex - offset, lastIndex);
}

void Board::initializeBishops() {
    int offset = 2;
    setChessPieceBoardIndex(new Bishop(getNextId(), PlayerID::PLAYER_1), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Bishop(getNextId(), PlayerID::PLAYER_1), lastIndex - offset, firstIndex);
    setChessPieceBoardIndex(new Bishop(getNextId(), PlayerID::PLAYER_2), firstIndex + offset, lastIndex);
    setChessPieceBoardIndex(new Bishop(getNextId(), PlayerID::PLAYER_2), lastIndex - offset, lastIndex);
}

void Board::initializeQueens() {
    int offset = 3;
    setChessPieceBoardIndex(new Queen(getNextId(), PlayerID::PLAYER_1), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Queen(getNextId(), PlayerID::PLAYER_2), firstIndex + offset, lastIndex);
}

void Board::initializeKings() {
    int offset = 4;
    setChessPieceBoardIndex(new King(getNextId(), PlayerID::PLAYER_1), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new King(getNextId(), PlayerID::PLAYER_2), firstIndex + offset, lastIndex);
}

void Board::initializePawns() {
    for (int i = 0; i < Board::boardSize; ++i) {
        setChessPieceBoardIndex(new Pawn(getNextId(), PlayerID::PLAYER_1), i, firstIndex + 1);
        setChessPieceBoardIndex(new Pawn(getNextId(), PlayerID::PLAYER_2), i, lastIndex - 1);
    }
}

void Board::initializeNullPieces() {
    for (int y = firstIndex + 2; y < Board::boardSize - 2; ++y) {
        for (int x = firstIndex; x < Board::boardSize; ++x) {
            setChessPieceBoardIndex(new NullPiece(), x, y);
        }
    }
}

void Board::initializeBoard() {
    this->initializeRooks();
    this->initializeKnights();
    this->initializeBishops();
    this->initializeQueens();
    this->initializeKings();
    this->initializePawns();
    this->initializeNullPieces();
}