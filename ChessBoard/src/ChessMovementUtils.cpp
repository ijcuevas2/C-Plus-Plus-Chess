//
// Created by ismael on 11/7/21.
//

#include "../headers/ChessMovementUtils.h"

void ChessMovementUtils::addBoardSpace(BoardSpace *boardSpace) {
    if (boardSpaceList.empty()
        && boardSpace != NULL
        && boardSpace->getChessPiece()->getPieceType() == PieceType::EMPTY_PIECE) {
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
        ChessMovementUtils::tryMovingChessPiece();
    }

    ChessMovementUtils::setBoardSpaceBackground(firstBoardSpace);
}

void ChessMovementUtils::showHints(BoardSpace *boardSpace) {
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

void ChessMovementUtils::hideHints() {
    int boardSize = gamePtr->getBoardSize();
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            BoardSpace* boardSpace = getBoardSpaceAtIndex(x, y);
            boardSpace->hideHint();
        }
    }
}

BoardSpace* ChessMovementUtils::getBoardSpaceAtIndex(int xIndex, int yIndex) {
    if (gamePtr != NULL) {
        return gamePtr->getBoardSpaceAtIndex(xIndex, yIndex);
    }

    return NULL;
}

void ChessMovementUtils::setBoardSpaceBackground(BoardSpace *boardSpace) {
    if (boardSpace == NULL) {
        return;
    }

    if (boardSpaceList.size() == 0) {
        boardSpace->setUnselectedBackground();
    } else {
        boardSpace->setSelectedBackground();
    }
}

bool ChessMovementUtils::haveSamePlayerId(Coordinates coordinates) {
    BoardSpace* firstBoardSpace = getBoardSpaceAtIndex(coordinates.sourceX, coordinates.sourceY);
    BoardSpace* secondBoardSpace = getBoardSpaceAtIndex(coordinates.targetX, coordinates.targetY);

    if (firstBoardSpace == NULL || secondBoardSpace == NULL) {
        return false;
    }

    return firstBoardSpace->getPlayerId() == secondBoardSpace->getPlayerId();
}

void ChessMovementUtils::tryMovingChessPiece() {
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

void ChessMovementUtils::moveChessPiece() {
    BoardSpace *firstBoardSpace = boardSpaceList[0];
    BoardSpace *secondBoardSpace = boardSpaceList[1];

    ChessPiece *firstChessPiece = firstBoardSpace->getChessPiece();
    ChessPiece *secondChessPiece = secondBoardSpace->getChessPiece();

    if (firstChessPiece->getPieceType() == PieceType::EMPTY_PIECE) {
        return;
    }

    delete secondChessPiece;
    EmptyPiece* emptyPiece = new EmptyPiece();

    firstBoardSpace->setChessPiece(emptyPiece);
    secondBoardSpace->setChessPiece(firstChessPiece);

    if (secondChessPiece->getPieceType() == PieceType::EMPTY_PIECE &&
        firstChessPiece->getPieceType() == PieceType::PAWN) {
        handleEnPassantCapture(firstBoardSpace, secondBoardSpace);
    }


    Coordinates coordinates(firstBoardSpace->getXIndex(), firstBoardSpace->getYIndex(),
                            secondBoardSpace->getXIndex(), secondBoardSpace->getYIndex());

    if (firstChessPiece->getPieceType() == PieceType::KING) {
        handleCastling(coordinates);
    }


    firstChessPiece->afterPieceMoved(coordinates);
    clearBoardSpaceList();
    incrementTurn();
}

// TODO: FIX MEMORY LEAK
void ChessMovementUtils::handleCastling(Coordinates coordinates) {
    if (coordinates.xAbsoluteDistance() == 2 && coordinates.yAbsoluteDistance() == 0) {
        // TODO: REFACTOR THESE VALUES
        BoardSpace* rookBoardSpace = NULL;
        BoardSpace* targetBoardSpace = NULL;
        int yIndex = coordinates.sourceY;

        if (coordinates.targetX == getFirstIndex() + 2) {
            rookBoardSpace = ChessMovementUtils::getBoardSpaceAtIndex(getFirstIndex(), yIndex);
            targetBoardSpace = ChessMovementUtils::getBoardSpaceAtIndex(getFirstIndex() + 3, yIndex);
        }

        if (coordinates.targetY == getLastIndex() - 1) {
            rookBoardSpace = ChessMovementUtils::getBoardSpaceAtIndex(getLastIndex(), yIndex);
            targetBoardSpace = ChessMovementUtils::getBoardSpaceAtIndex(getLastIndex() - 2, yIndex);
        }

        if (rookBoardSpace != NULL && targetBoardSpace != NULL) {
            EmptyPiece* emptyPiece = new EmptyPiece();
            ChessPiece* rookPtr = rookBoardSpace->getChessPiece();

            ChessPiece* currChessPiecePtr = targetBoardSpace->getChessPiece();
            delete currChessPiecePtr;

            rookBoardSpace->setChessPiece(emptyPiece);
            targetBoardSpace->setChessPiece(rookPtr);
        }
    }
}

void ChessMovementUtils::handleEnPassantCapture(BoardSpace *firstBoardSpace, BoardSpace *secondBoardSpace) {
    int targetPieceX = secondBoardSpace->getXIndex();
    int targetPieceY = firstBoardSpace->getYIndex();
    int enPassantTurn = ChessMovementUtils::getMovedTwoSpacesTurn(targetPieceX, targetPieceY) + 1;
    if (enPassantTurn == ChessMovementUtils::getCurrentTurn()) {
        EmptyPiece *targetEmptyPiece = new EmptyPiece();
        setChessPieceAtIndex(targetEmptyPiece, targetPieceX, targetPieceY);
    }
}

void ChessMovementUtils::handlePawnPromotion(Coordinates coordinates) {
    ChessPiece* chessPiece = getChessPieceAtIndex(coordinates.targetX, coordinates.targetY);
    bool isEligibleForPromotion = isPawnEligibleForPromotion(chessPiece, coordinates);
    if (isEligibleForPromotion) {
        PawnPromotionView* pawnPromotionView = new PawnPromotionView(nullptr, coordinates=coordinates);
        pawnPromotionView->show();
    }
}

bool ChessMovementUtils::isPawnEligibleForPromotion(ChessPiece *chessPiece, Coordinates coordinates) {
    bool isEligibleForPromotion =  (chessPiece->getPlayerId() == PlayerID::PLAYER_LIGHT
                                   && coordinates.targetY == getFirstIndex())
                                   || (chessPiece->getPlayerId() == PlayerID::PLAYER_DARK
                                   && coordinates.targetY == getLastIndex());
    return isEligibleForPromotion;
}

int ChessMovementUtils::getFirstIndex() {
    return firstIndex;
}

int ChessMovementUtils::getLastIndex() {
    return lastIndex;
}

int ChessMovementUtils::getBoardSize() {
    return boardSize;
}

void ChessMovementUtils::clearBoardSpaceList() {
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

void ChessMovementUtils::incrementTurn() {
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

bool ChessMovementUtils::isTurnPlayerPiece(ChessPiece *chessPiece) {
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

const bool ChessMovementUtils::canMove(BoardSpace *firstBoardSpace, BoardSpace *secondBoardSpace) {
    if (firstBoardSpace == secondBoardSpace) {
        return false;
    }

    const int destX = secondBoardSpace->getXIndex();
    const int destY = secondBoardSpace->getXIndex();

    return firstBoardSpace->canMovePieceToIndex(destX, destY);
}

void ChessMovementUtils::setLabelPtr(QLabel *qLabel) {
    turnLabelPtr = qLabel;
}

void ChessMovementUtils::setGamePtr(Game *game) {
    gamePtr = game;
}

bool ChessMovementUtils::isBoardIndexOccupied(int targetX, int targetY) {
    if (gamePtr != NULL) {
        ChessPiece *chessPiecePtr = gamePtr->getChessPieceAtBoardIndex(targetX, targetY);
        if (chessPiecePtr != NULL) {
            PieceType pieceType = chessPiecePtr->getPieceType();
            return pieceType != PieceType::EMPTY_PIECE;
        }
    }

    return false;
}

int ChessMovementUtils::getMovedTwoSpacesTurn(int targetX, int targetY) {
    ChessPiece *chessPiece = getChessPieceAtIndex(targetX, targetY);
    if (chessPiece != NULL && chessPiece->getPieceType() == PieceType::PAWN) {
        // TODO: INVESTIGATE DYNAMIC CAST
        Pawn *pawn = dynamic_cast<Pawn*>(chessPiece);
        int turn = pawn->getMovedTwoSpacesTurn();
        return turn;
    }

    return -1;
}

ChessPiece* ChessMovementUtils::getChessPieceAtIndex(int xIndex, int yIndex) {
    if (gamePtr != NULL) {
        ChessPiece *chessPiecePtr = gamePtr->getChessPieceAtBoardIndex(xIndex, yIndex);
        return chessPiecePtr;
    }

    return NULL;
}

void ChessMovementUtils::setChessPieceAtIndex(ChessPiece *chessPiece, int targetX, int targetY) {
    if (gamePtr != NULL) {
        gamePtr->setChessPieceAtBoardIndex(chessPiece, targetX, targetY);
    }
}

int ChessMovementUtils::getCurrentTurn() {
    return currentTurn;
}

PlayerID ChessMovementUtils::getCurrentTurnPlayerId() {
    if (getCurrentTurn() % 2 == 0) {
        return PlayerID::PLAYER_DARK;
    } else {
        return PlayerID::PLAYER_LIGHT;
    }
}

void ChessMovementUtils::afterPawnMoved() {

}

