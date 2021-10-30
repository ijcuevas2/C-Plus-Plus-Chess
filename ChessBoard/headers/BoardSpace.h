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
    ChessPiece* chessPiece;
public:
    BoardSpace(ChessPiece *chessPiece, int xIndex, int yIndex)
            : QGraphicsRectItem(), chessPiece(chessPiece) {
        const int pointX = xIndex * Resources::SQUARE_SIZE;
        const int pointY = yIndex * Resources::SQUARE_SIZE;
        setRect(0, 0, Resources::SQUARE_SIZE, Resources::SQUARE_SIZE);
        setPos(pointX, pointY);
        this->chessPiece->setParentItem(this);
        const bool filledBackground = ((xIndex + yIndex) % 2) == 1;
        if (filledBackground) {
            QBrush brush(Qt::gray);
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
