//
// Created by ismael on 9/29/21.
//

#ifndef CHESS_CHESSPIECE_H
#define CHESS_CHESSPIECE_H

#include "../../enums/PieceType.h"
#include "../../enums/Player.h"
#include "Resources.h"
#include "Coordinates.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <iostream>

class ChessPiece: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    ChessPiece(PlayerID playerId, PieceType pieceType) : QObject(), QGraphicsPixmapItem() {
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

    // TODO: REMOVE THIS CODE
    std::string getChessPieceImagePath() {
        if (pieceType == PieceType::NULL_PIECE) {
            return "NULL_PIECE";
        }

        std::string imagePath = Resources::getImagePath(playerId, pieceType);
        return imagePath;
    }

    int pieceMovement(int source, int dest);
    int absoluteDistance(int source, int dest);
    PlayerID getPlayerId();
    PieceType getPieceType();
    virtual bool canMove(int sourceX, int sourceY, int destX, int destY) = 0;
protected:
    PieceType pieceType;
    PlayerID playerId;
};

#endif //CHESS_CHESSPIECE_H
