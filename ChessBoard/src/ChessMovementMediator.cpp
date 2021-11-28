//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementMediator.h"
#include "../headers/ChessPieces/Pawn.h"
#include <QGraphicsView>


void ChessMovementMediator::addBoardSpace(BoardSpace* boardSpace) {
    if (boardSpaceList.empty()
        && boardSpace != NULL
        && boardSpace->getChessPiece()->getPieceType() == PieceType::NULL_PIECE) {
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

    if (boardSpaceList.size() == 2 && boardSpaceList[0] != NULL && boardSpaceList[1] != NULL) {
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

    const bool selectedPieceCanMove = firstBoardSpace->canMove(destX, destY);

    if (selectedPieceCanMove) {
        // TODO: Check if increment turn can be moved
        moveChessPiece();
    } else {
        clearBoardSpaceList();
    }
}

void ChessMovementMediator::moveChessPiece() {
    BoardSpace* firstBoardSpace = boardSpaceList[0];
    BoardSpace* secondBoardSpace = boardSpaceList[1];

    ChessPiece* firstChessPiece = firstBoardSpace->getChessPiece();
    ChessPiece* secondChessPiece = secondBoardSpace->getChessPiece();

    if (firstChessPiece->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    delete secondChessPiece;
    NullPiece* nullPiece = new NullPiece();

    firstBoardSpace->setChessPiece(nullPiece);
    secondBoardSpace->setChessPiece(firstChessPiece);

    if (secondChessPiece->getPieceType() == PieceType::NULL_PIECE && firstChessPiece->getPieceType() == PieceType::PAWN) {
        int targetPieceX = secondBoardSpace->getXIndex();
        int targetPieceY = firstBoardSpace->getYIndex();
        NullPiece* targetPieceNullPiece = new NullPiece();
        setChessPieceAtIndex(targetPieceNullPiece, targetPieceX, targetPieceY);
    }

    clearBoardSpaceList();
    incrementTurn();
}

void ChessMovementMediator::clearBoardSpaceList() {
    boardSpaceList.clear();
}

void ChessMovementMediator::incrementTurn() {
    // TODO: Check for overflow
    currentTurn++;

    if (turnLabelPtr != NULL) {
        std::string title = "Current Turn ";

        if (currentTurn % 2 == 0) {
            title += "(Dark Turn)";
        } else {
            title += "(Light Turn)";
        }

        title += ": ";
        title += std::to_string(currentTurn);

        QString qTitle = QString::fromStdString(title);
        turnLabelPtr->setText(qTitle);
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
    turnLabelPtr = qLabel;
}

void ChessMovementMediator::setGamePtr(Game* game) {
    gamePtr = game;
}

bool ChessMovementMediator::isBoardIndexOccupied(int targetX, int targetY) {
    if (gamePtr != NULL) {
        ChessPiece* chessPiecePtr = gamePtr->getChessPieceBoardIndex(targetX, targetY);
        if (chessPiecePtr != NULL) {
            PieceType pieceType = chessPiecePtr->getPieceType();
            return pieceType != PieceType::NULL_PIECE;
        }
    }

    return false;
}

int ChessMovementMediator::getMovedTwoSpacesTurn(int targetX, int targetY) {
    ChessPiece* chessPiece = getChessPieceAtIndex(targetX, targetY);
    if (chessPiece != NULL && chessPiece->getPieceType() == PieceType::PAWN) {
        Pawn* pawn = static_cast<Pawn*>(chessPiece);
        int turn = pawn->getMovedTwoSpacesTurn();
        return turn;
    }

    return -1;
}

ChessPiece* ChessMovementMediator::getChessPieceAtIndex(int targetX, int targetY) {
    if (gamePtr != NULL) {
        ChessPiece* chessPiecePtr = gamePtr->getChessPieceBoardIndex(targetX, targetY);
        return chessPiecePtr;
    }

    return NULL;
}

void ChessMovementMediator::setChessPieceAtIndex(ChessPiece* chessPiece, int targetX, int targetY) {
    if (gamePtr != NULL) {
        gamePtr->setChessPieceBoardIndex(chessPiece, targetX, targetY);
    }
}

int ChessMovementMediator::getCurrentTurn() {
    return currentTurn;
}