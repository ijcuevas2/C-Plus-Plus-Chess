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
    bool darkBackground;
    int xIndex;
    int yIndex;
public:
    int getXIndex() const;
    int getYIndex() const;
public:
    BoardSpace(ChessPiece *chessPiece, int xIndex, int yIndex)
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
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setSelectedBackground();
    void setUnselectedBackground();

    virtual ~BoardSpace() {
        delete chessPiece;
    }

   void setChessPiece(ChessPiece* chessPiece) {
        this->chessPiece = chessPiece;
        this->chessPiece->setParentItem(this);
    }

    ChessPiece* getChessPiece() {
        return chessPiece;
    }

    bool canMovePieceToIndex(int destX, int destY) {
        Coordinates coordinates(xIndex, yIndex, destX, destY);
        return chessPiece->canMove(coordinates);
    }
};


#endif //CHESS_BOARDSPACE_H
