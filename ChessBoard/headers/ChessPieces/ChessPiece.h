//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include "../../enums/PieceType.h"
#include "../../enums/Player.h"
#include "Resources.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <iostream>

class ChessPiece: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    virtual bool movement(int source_x, int source_y, int dest_x, int dest_y) = 0;
public:
    ChessPiece(PlayerID playerId, PieceType pieceType, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
        this->playerId = playerId;
        this->pieceType = pieceType;
        this->setChessPieceImagePath();
    }

    virtual ~ChessPiece() {};
    void setChessPieceImagePath() {
        if (pieceType == PieceType::NULL_PIECE) {
            return;
        }

        std::string imagePath = Resources::getImagePath(playerId, pieceType);
        char filePath[imagePath.length() + 1];
        strcpy(filePath, imagePath.c_str());
        setPixmap(QPixmap(filePath));
    }

    bool samePiece(int source_x, int source_y, int dest_x, int dest_y);
    bool reachedDestination(int source_x, int source_y, int dest_x, int dest_y);
    int pieceDisplacement(int source, int dest);
    int absolutePieceDisplacement(int source, int dest);
    PlayerID getPlayerId();
    virtual PieceType getPieceType();
protected:
    PieceType pieceType;
    PlayerID playerId;
};

#endif //CHESS_CHESSPIECE_H
