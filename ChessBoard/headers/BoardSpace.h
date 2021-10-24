//
// Created by ismael on 10/24/21.
//

#ifndef CHESS_BOARDSPACE_H
#define CHESS_BOARDSPACE_H
#include <QGraphicsRectItem>
#include <QBrush>
#include "ChessPieces/ChessPiece.h"
#include "Point.h"
#include "ChessPieces/Resources.h"

class BoardSpace: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    Point point;
    ChessPiece* chessPiece;
public:
    BoardSpace(ChessPiece* chessPiece, Point p1, QGraphicsItem *parent = nullptr) : QGraphicsRectItem(parent), chessPiece(chessPiece), point(p1) {
        const int pointX = point.getX();
        const int pointY = point.getY();
        setRect(pointX * Resources::SQUARE_SIZE, pointY * Resources::SQUARE_SIZE, Resources::SQUARE_SIZE, Resources::SQUARE_SIZE);
        const bool filledBackground = ((pointX + pointY) % 2) == 1;
        chessPiece->setParentItem(this);
        if (filledBackground) {
            QBrush brush(Qt::black);
            setBrush(brush);
        }
    }
    virtual ~BoardSpace() {
        delete chessPiece;
    }

    ChessPiece* getChessPiece() {
        return chessPiece;
    }
};


#endif //CHESS_BOARDSPACE_H
