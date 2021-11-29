//
// Created by ismael on 10/24/21.
//

#include "../headers/BoardSpace.h"
#include "../headers/ChessMovementMediator.h"
#include <QGraphicsItemGroup>
#include <QGraphicsView>


void BoardSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    ChessMovementMediator::addBoardSpace(this);
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
