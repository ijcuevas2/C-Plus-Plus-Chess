//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementMediator.h"

void ChessMovementMediator::addChessPiece(BoardSpace* boardSpace) {
    if (boardSpaceList.size() > -1 && boardSpaceList.size() < 2) {
        boardSpaceList.push_back(boardSpace);
    }

    if (boardSpaceList.size() == 2 && boardSpaceList[0] != NULL && boardSpaceList[1] != NULL) {
        ChessMovementMediator::movePieces();
    }
}

void ChessMovementMediator::movePieces() {
    BoardSpace* firstBoardSpace = boardSpaceList[0];
    BoardSpace* secondBoardSpace = boardSpaceList[1];

    int destX = 0;
    int destY = 0;

    if (secondBoardSpace != NULL) {
        destX = secondBoardSpace->getXIndex();
        destY = secondBoardSpace->getYIndex();
    }

    firstBoardSpace->canMove(destX, destY);
}

const bool canMove(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace) {
    if (firstBoardSpace == secondBoardSpace) {
        return false;
    }

    const int destX = secondBoardSpace->getXIndex();
    const int destY = secondBoardSpace->getXIndex();

    firstBoardSpace->canMove(destX, destY);

    return false;
}