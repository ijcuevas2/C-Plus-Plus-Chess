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
    setChessPieceBoardIndex(new Rook(PlayerID::PLAYER_DARK), firstIndex, firstIndex);
    setChessPieceBoardIndex(new Rook(PlayerID::PLAYER_DARK), lastIndex, firstIndex);
    setChessPieceBoardIndex(new Rook(PlayerID::PLAYER_LIGHT), firstIndex, lastIndex);
    setChessPieceBoardIndex(new Rook(PlayerID::PLAYER_LIGHT), lastIndex, lastIndex);
}

void Game::initializeKnights() {
    int offset = 1;
    setChessPieceBoardIndex(new Knight(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Knight(PlayerID::PLAYER_DARK), lastIndex - offset, firstIndex);
    setChessPieceBoardIndex(new Knight(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
    setChessPieceBoardIndex(new Knight(PlayerID::PLAYER_LIGHT), lastIndex - offset, lastIndex);
}

void Game::initializeBishops() {
    int offset = 2;
    setChessPieceBoardIndex(new Bishop(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Bishop(PlayerID::PLAYER_DARK), lastIndex - offset, firstIndex);
    setChessPieceBoardIndex(new Bishop(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
    setChessPieceBoardIndex(new Bishop(PlayerID::PLAYER_LIGHT), lastIndex - offset, lastIndex);
}

void Game::initializeQueens() {
    int offset = 3;
    setChessPieceBoardIndex(new Queen(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new Queen(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
}

void Game::initializeKings() {
    int offset = 4;
    setChessPieceBoardIndex(new King(PlayerID::PLAYER_DARK), firstIndex + offset, firstIndex);
    setChessPieceBoardIndex(new King(PlayerID::PLAYER_LIGHT), firstIndex + offset, lastIndex);
}

void Game::initializePawns() {
    for (int i = 0; i < Game::boardSize; ++i) {
        setChessPieceBoardIndex(new Pawn(PlayerID::PLAYER_DARK), i, firstIndex + 1);
        setChessPieceBoardIndex(new Pawn(PlayerID::PLAYER_LIGHT), i, lastIndex - 1);
    }
}

void Game::initializeNullPieces() { for (int y = firstIndex + 2; y < Game::boardSize - 2; ++y) {
        for (int x = firstIndex; x < Game::boardSize; ++x) {
            setChessPieceBoardIndex(new NullPiece(), x, y);
        }
    }
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