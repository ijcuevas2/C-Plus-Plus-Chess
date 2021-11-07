//
// Created by ismael on 10/24/21.
//

#include "../headers/BoardSpace.h"
#include <QGraphicsItemGroup>


void BoardSpace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    std::cout << "BoardSpace Mouse Pressed!!" << std::endl;
    QGraphicsItem::mousePressEvent(event);
//    this->parentItem()->mousePressEvent(event);
//    QGraphicsItemGroup::mousePressEvent(event);
}

int BoardSpace::getXIndex() const {
    return xIndex;
}

int BoardSpace::getYIndex() const {
    return yIndex;
}
