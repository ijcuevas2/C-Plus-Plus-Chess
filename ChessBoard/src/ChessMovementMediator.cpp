//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementMediator.h"
#include "../headers/ChessPieces/Pawn.h"
#include <QGraphicsView>

void ChessMovementMediator::addBoardSpace(BoardSpace *boardSpace) {
    if (boardSpaceList.empty()
        && boardSpace != NULL
        && boardSpace->getChessPiece()->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    ChessPiece *currPiece = boardSpace->getChessPiece();

    if (boardSpaceList.empty()) {
        bool isTurnPlayerPieceValue = isTurnPlayerPiece(currPiece);
        if (!isTurnPlayerPieceValue) {
            return;
        }
    }

    if (boardSpaceList.size() < 2) {
        boardSpaceList.push_back(boardSpace);
        showHints(boardSpace);
    }

    size_t boardSpaceSize = boardSpaceList.size();
    BoardSpace *firstBoardSpace = boardSpaceSize > 0 ? boardSpaceList[0] : NULL;

    if (boardSpaceList.size() == 2 && boardSpaceList[0] != NULL && boardSpaceList[1] != NULL) {
        ChessMovementMediator::tryMovingChessPiece();
    }

    ChessMovementMediator::setBoardSpaceBackground(firstBoardSpace);
}

void ChessMovementMediator::showHints(BoardSpace *boardSpace) {
    if (boardSpace != NULL) {
        int boardSize = gamePtr->getBoardSize();
        for (int y = 0; y < boardSize; y++) {
            for (int x = 0; x < boardSize; x++) {
                bool canMoveToIndex = boardSpace->canMovePieceToIndex(x, y);
                if (canMoveToIndex) {
                    BoardSpace* targetBoardSpace = getBoardSpaceAtIndex(x, y);
                    if (targetBoardSpace != NULL) {
                        targetBoardSpace->showHint();
                    }
                }
            }
        }
    }
}

void ChessMovementMediator::hideHints() {
    int boardSize = gamePtr->getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            BoardSpace* boardSpace = getBoardSpaceAtIndex(x, y);
            boardSpace->hideHint();
        }
    }
}

BoardSpace* ChessMovementMediator::getBoardSpaceAtIndex(int xIndex, int yIndex) {
    if (gamePtr != NULL) {
        return gamePtr->getBoardSpaceAtIndex(xIndex, yIndex);
    }

    return NULL;
}

void ChessMovementMediator::setBoardSpaceBackground(BoardSpace *boardSpace) {
    if (boardSpace == NULL) {
        return;
    }

    if (boardSpaceList.size() == 0) {
        boardSpace->setUnselectedBackground();
    } else {
        boardSpace->setSelectedBackground();
    }
}

bool ChessMovementMediator::haveSamePlayerId(Coordinates coordinates) {
    BoardSpace* firstBoardSpace = getBoardSpaceAtIndex(coordinates.sourceX, coordinates.sourceY);
    BoardSpace* secondBoardSpace = getBoardSpaceAtIndex(coordinates.destX, coordinates.destY);

    if (firstBoardSpace == NULL || secondBoardSpace == NULL) {
        return false;
    }

    return firstBoardSpace->getPlayerId() == secondBoardSpace->getPlayerId();
}

void ChessMovementMediator::tryMovingChessPiece() {
    BoardSpace *firstBoardSpace = boardSpaceList[0];
    BoardSpace *secondBoardSpace = boardSpaceList[1];

    int destX = 0;
    int destY = 0;

    if (secondBoardSpace != NULL) {
        destX = secondBoardSpace->getXIndex();
        destY = secondBoardSpace->getYIndex();
    }

    const bool selectedPieceCanMove = firstBoardSpace->canMovePieceToIndex(destX, destY);

    if (selectedPieceCanMove) {
        // TODO: Check if increment turn can be moved
        moveChessPiece();
    } else {
        clearBoardSpaceList();
    }
}

void ChessMovementMediator::moveChessPiece() {
    BoardSpace *firstBoardSpace = boardSpaceList[0];
    BoardSpace *secondBoardSpace = boardSpaceList[1];

    ChessPiece *firstChessPiece = firstBoardSpace->getChessPiece();
    ChessPiece *secondChessPiece = secondBoardSpace->getChessPiece();

    if (firstChessPiece->getPieceType() == PieceType::NULL_PIECE) {
        return;
    }

    delete secondChessPiece;
    NullPiece *nullPiece = new NullPiece();

    firstBoardSpace->setChessPiece(nullPiece);
    secondBoardSpace->setChessPiece(firstChessPiece);

    if (secondChessPiece->getPieceType() == PieceType::NULL_PIECE &&
        firstChessPiece->getPieceType() == PieceType::PAWN) {
        handleEnPassantCapture(firstBoardSpace, secondBoardSpace);
    }

    Coordinates coordinates(firstBoardSpace->getXIndex(), firstBoardSpace->getYIndex(),
                            secondBoardSpace->getXIndex(), secondBoardSpace->getYIndex());
    firstChessPiece->afterPieceMoved(coordinates);
    clearBoardSpaceList();
    incrementTurn();
}

void ChessMovementMediator::handleEnPassantCapture(BoardSpace *firstBoardSpace, BoardSpace *secondBoardSpace) {
    int targetPieceX = secondBoardSpace->getXIndex();
    int targetPieceY = firstBoardSpace->getYIndex();
    int enPassantTurn = ChessMovementMediator::getMovedTwoSpacesTurn(targetPieceX, targetPieceY) + 1;
    if (enPassantTurn == ChessMovementMediator::getCurrentTurn()) {
        NullPiece *targetPieceNullPiece = new NullPiece();
        setChessPieceAtIndex(targetPieceNullPiece, targetPieceX, targetPieceY);
    }
}

void ChessMovementMediator::clearBoardSpaceList() {
    BoardSpace *firstBoardSpace = NULL;
    if (!boardSpaceList.empty()) {
        firstBoardSpace = boardSpaceList[0];
    }
    boardSpaceList.clear();

    if (firstBoardSpace != NULL) {
        setBoardSpaceBackground(firstBoardSpace);
    }

    hideHints();
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

bool ChessMovementMediator::isTurnPlayerPiece(ChessPiece *chessPiece) {
    PlayerID playerId = chessPiece->getPlayerId();
    std::map<PlayerID, int> playerIdMap = {{PlayerID::PLAYER_LIGHT, 0},
                                           {PlayerID::PLAYER_DARK,  1}};
    int playerIdCount = playerIdMap.count(playerId);
    if (playerIdCount < 1) {
        return false;
    }

    int isTurnPlayerId = playerIdMap[playerId];
    bool isTurnPlayer = (currentTurn + 1) % 2 == isTurnPlayerId;
    return isTurnPlayer;
}

const bool ChessMovementMediator::canMove(BoardSpace *firstBoardSpace, BoardSpace *secondBoardSpace) {
    if (firstBoardSpace == secondBoardSpace) {
        return false;
    }

    const int destX = secondBoardSpace->getXIndex();
    const int destY = secondBoardSpace->getXIndex();

    return firstBoardSpace->canMovePieceToIndex(destX, destY);
}

void ChessMovementMediator::setLabelPtr(QLabel *qLabel) {
    turnLabelPtr = qLabel;
}

void ChessMovementMediator::setGamePtr(Game *game) {
    gamePtr = game;
}

bool ChessMovementMediator::isBoardIndexOccupied(int targetX, int targetY) {
    if (gamePtr != NULL) {
        ChessPiece *chessPiecePtr = gamePtr->getChessPieceAtBoardIndex(targetX, targetY);
        if (chessPiecePtr != NULL) {
            PieceType pieceType = chessPiecePtr->getPieceType();
            return pieceType != PieceType::NULL_PIECE;
        }
    }

    return false;
}

int ChessMovementMediator::getMovedTwoSpacesTurn(int targetX, int targetY) {
    ChessPiece *chessPiece = getChessPieceAtIndex(targetX, targetY);
    if (chessPiece != NULL && chessPiece->getPieceType() == PieceType::PAWN) {
        // TODO: INVESTIGATE DYNAMIC CAST
        Pawn *pawn = dynamic_cast<Pawn *>(chessPiece);
        int turn = pawn->getMovedTwoSpacesTurn();
        return turn;
    }

    return -1;
}

ChessPiece *ChessMovementMediator::getChessPieceAtIndex(int targetX, int targetY) {
    if (gamePtr != NULL) {
        ChessPiece *chessPiecePtr = gamePtr->getChessPieceAtBoardIndex(targetX, targetY);
        return chessPiecePtr;
    }

    return NULL;
}

void ChessMovementMediator::setChessPieceAtIndex(ChessPiece *chessPiece, int targetX, int targetY) {
    if (gamePtr != NULL) {
        gamePtr->setChessPieceAtBoardIndex(chessPiece, targetX, targetY);
    }
}

int ChessMovementMediator::getCurrentTurn() {
    return currentTurn;
}

PlayerID ChessMovementMediator::getCurrentTurnPlayerId() {
    std::map<PlayerID, int> playerIdMap = {{PlayerID::PLAYER_LIGHT, 0},
                                           {PlayerID::PLAYER_DARK,  1}};
    if (getCurrentTurn() % 2 == 0) {
        return PlayerID::PLAYER_LIGHT;
    } else {
        return PlayerID::PLAYER_DARK;
    }
}

