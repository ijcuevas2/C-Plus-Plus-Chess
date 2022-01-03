//
// Created by ismael on 12/20/21.
//

#ifndef CHESS_HINTMARKER_H
#define CHESS_HINTMARKER_H
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include "Point.h"
#include "ChessPieces/Resources.h"

class HintMarker: public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    HintMarker();
};


#endif //CHESS_HINTMARKER_H
