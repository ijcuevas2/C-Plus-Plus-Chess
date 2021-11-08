//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementMediator.h"
#include <QGraphicsView>
void ChessMovementMediator::addBoardSpace(BoardSpace* boardSpace) {
    if (boardSpaceList.empty() && boardSpace->getChessPiece()->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    if (boardSpaceList.size() < 2) {
        std::cout << "Pushing Back" << boardSpace->getChessPiece()->getChessPieceImagePath() << std::endl;
        boardSpaceList.push_back(boardSpace);
    }

    size_t boardSpaceSize = boardSpaceList.size();
    BoardSpace* firstBoardSpace = boardSpaceSize > 0 ? boardSpaceList[0] : NULL;

    if (boardSpaceList.size() == 2 && boardSpaceList[0] != NULL && boardSpaceList[1] != NULL) {
        ChessMovementMediator::movePieces();
    }

    ChessMovementMediator::setBoardSpaceBackground(firstBoardSpace);
}

void ChessMovementMediator::setBoardSpaceBackground(BoardSpace* boardSpace) {
    if (boardSpace == NULL) {
        return;
    }

    if(boardSpaceList.size() == 0) {
        boardSpace->setUnselectedBackground();
    } else {
        boardSpace->setSelectedBackground();
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

    const bool firstPieceCanMove = firstBoardSpace->canMove(destX, destY);

    if (firstPieceCanMove) {
        ChessPiece* firstChessPiece = firstBoardSpace->getChessPiece();
        ChessPiece* secondChessPiece = secondBoardSpace->getChessPiece();
        firstBoardSpace->setChessPiece(secondChessPiece);
        secondBoardSpace->setChessPiece(firstChessPiece);
        boardSpaceList.clear();
    }
}

const bool canMove(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace) {
    if (firstBoardSpace == secondBoardSpace) {
        return false;
    }

    const int destX = secondBoardSpace->getXIndex();
    const int destY = secondBoardSpace->getXIndex();

    return firstBoardSpace->canMove(destX, destY);
}