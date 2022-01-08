//
// Created by ismael on 10/24/21.
//

#include "../headers/BoardSpace.h"
#include "../headers/ChessMovementUtils.h"
#include <QGraphicsItemGroup>
#include <QGraphicsView>

BoardSpace::BoardSpace(ChessPiece *chessPiece, int xIndex, int yIndex)
        : QGraphicsRectItem(), chessPiece(chessPiece), xIndex(xIndex), yIndex(yIndex) {
    const int pointX = xIndex * Resources::SQUARE_SIZE;
    const int pointY = yIndex * Resources::SQUARE_SIZE;
    setRect(0, 0, Resources::SQUARE_SIZE, Resources::SQUARE_SIZE);
    setPos(pointX, pointY);
    this->chessPiece->setParentItem(this);
    // TODO: ADD ASSERTS
    this->darkBackground = ((xIndex + yIndex) % 2) == 1;
    if (this->darkBackground) {
        QBrush brush(Qt::gray);
        setBrush(brush);
    }

    initMarker();
}

void BoardSpace::showHint() {
    if (hintMarkerPtr != NULL) {
        hintMarkerPtr->show();
    }
}

void BoardSpace::hideHint() {
    if (hintMarkerPtr != NULL) {
        hintMarkerPtr->hide();
    }
}

void BoardSpace::initMarker() {
    hintMarkerPtr = new HintMarker();
    hintMarkerPtr->setParentItem(this);
}

void BoardSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    ChessMovementUtils::addBoardSpace(this);
}

void BoardSpace::setSelectedBackground() {
    QBrush brush(Qt::darkGreen);
    setBrush(brush);
}

void BoardSpace::setUnselectedBackground() {
    if (this->darkBackground) {
        QBrush brush(Qt::gray);
        setBrush(brush);
    } else {
        QBrush brush(Qt::white);
        setBrush(brush);
    }
}

int BoardSpace::getXIndex() const {
    return xIndex;
}

int BoardSpace::getYIndex() const {
    return yIndex;
}

ChessPiece* BoardSpace::getChessPiece() {
    return chessPiece;
}

PlayerID BoardSpace::getPlayerId() {
    if (chessPiece != NULL) {
        return chessPiece->getPlayerId();
    }

    return PlayerID::NONE;
}

void BoardSpace::setChessPiece(ChessPiece *chessPiece) {
    this->chessPiece = chessPiece;
    this->chessPiece->setParentItem(this);
}

bool BoardSpace::canMovePieceToIndex(int destX, int destY) {
    Coordinates coordinates(xIndex, yIndex, destX, destY);
    bool haveSamePlayerIdValue = ChessMovementUtils::haveSamePlayerId(coordinates);
    if (haveSamePlayerIdValue) {
        return false;
    }

    bool canMoveValue = chessPiece->canMove(coordinates);
    return canMoveValue;
}
