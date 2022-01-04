//
// Created by ismael on 12/20/21.
//

#include "../headers/HintMarker.h"

HintMarker::HintMarker() {
    setRect(0, 0, Resources::MARKER_SIZE, Resources::MARKER_SIZE);
    // TODO: Change color for marker
    QColor limeGreen("#32CD32");
    QBrush brush(limeGreen);
    setBrush(brush);
    this->setPos(21.5, 21.5);
    QPen pen(Qt::NoPen);
    this->setPen(pen);
    this->hide();
    this->setZValue(10);
}
