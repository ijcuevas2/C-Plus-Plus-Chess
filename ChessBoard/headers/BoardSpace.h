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
#include "HintMarker.h"

class BoardSpace: public QObject, public QGraphicsRectItem {
    Q_OBJECT
private:
    ChessPiece* chessPiece;
    HintMarker* hintMarkerPtr;
    bool darkBackground;
    int xIndex;
    int yIndex;
public:
    int getXIndex() const;
    int getYIndex() const;
public:

    BoardSpace(ChessPiece* chessPiece, int xIndex, int yIndex);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setSelectedBackground();
    void setUnselectedBackground();
    ChessPiece* getChessPiece();
    PlayerID getPlayerId();
    void setChessPiece(ChessPiece* chessPiece);
    void initMarker();
    bool canMovePieceToIndex(int destX, int destY);
    void showHint();
    void hideHint();

    virtual ~BoardSpace() {
        delete chessPiece;
        delete hintMarkerPtr;
    }

};


#endif //CHESS_BOARDSPACE_H
