//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementMediator.h"
#include <QGraphicsView>


void ChessMovementMediator::addBoardSpace(BoardSpace* boardSpace) {
    if (boardSpaceList.empty()
        and boardSpace != NULL
        and boardSpace->getChessPiece()->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    ChessPiece* currPiece = boardSpace->getChessPiece();

    if (boardSpaceList.empty()) {
        bool canMovePiece = isTurnPlayerPiece(currPiece);
        if (!canMovePiece) {
            return;
        }
    }

    if (boardSpaceList.size() < 2) {
        boardSpaceList.push_back(boardSpace);
    }

    size_t boardSpaceSize = boardSpaceList.size();
    BoardSpace* firstBoardSpace = boardSpaceSize > 0 ? boardSpaceList[0] : NULL;

    if (boardSpaceList.size() == 2 and boardSpaceList[0] != NULL and boardSpaceList[1] != NULL) {
        ChessMovementMediator::tryMovingChessPiece();
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

void ChessMovementMediator::tryMovingChessPiece() {
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
        // TODO: Check if increment turn can be moved
        moveChessPiece();
    } else {
        clearBoardSpace();
    }
}

void ChessMovementMediator::moveChessPiece() {
    BoardSpace* firstBoardSpace = boardSpaceList[0];
    BoardSpace* secondBoardSpace = boardSpaceList[1];

    ChessPiece* sourceChessPiece = firstBoardSpace->getChessPiece();
    ChessPiece* secondChessPiece = secondBoardSpace->getChessPiece();

    if (sourceChessPiece->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    delete secondChessPiece;
    secondChessPiece = new NullPiece();

    firstBoardSpace->setChessPiece(secondChessPiece);
    secondBoardSpace->setChessPiece(sourceChessPiece);
    clearBoardSpace();
    incrementTurn();
}

void ChessMovementMediator::clearBoardSpace() {
    boardSpaceList.clear();
}

void ChessMovementMediator::incrementTurn() {
    // TODO: Check for overflow
    currentTurn++;

    if (qLabelPtr not_eq NULL) {
        std::string title = "Current Turn ";

        if (currentTurn % 2 == 0) {
            title += "(Dark Turn)";
        } else {
            title += "(Light Turn)";
        }

        title += ": ";
        title += std::to_string(currentTurn);

        QString qTitle = QString::fromStdString(title);
        qLabelPtr->setText(qTitle);
    }
}

bool ChessMovementMediator::isTurnPlayerPiece(ChessPiece* chessPiece) {
    PlayerID playerId = chessPiece->getPlayerId();
    std::map<PlayerID, int> playerIdMap = {{PlayerID::PLAYER_LIGHT, 0},
                                           {PlayerID::PLAYER_DARK, 1 }};
    int playerIdCount = playerIdMap.count(playerId);
    if (playerIdCount < 1) {
        return false;
    }

    int isTurnPlayerId = playerIdMap[playerId];
    bool isTurnPlayer = (currentTurn + 1) % 2 == isTurnPlayerId;
    return isTurnPlayer;
}

const bool ChessMovementMediator::canMove(BoardSpace* firstBoardSpace, BoardSpace* secondBoardSpace) {
    if (firstBoardSpace == secondBoardSpace) {
        return false;
    }

    const int destX = secondBoardSpace->getXIndex();
    const int destY = secondBoardSpace->getXIndex();

    return firstBoardSpace->canMove(destX, destY);
}

void ChessMovementMediator::setLabelPtr(QLabel* qLabel) {
    qLabelPtr = qLabel;
}

bool ChessMovementMediator::isFirstTurn() {
    return currentTurn == 1;
}