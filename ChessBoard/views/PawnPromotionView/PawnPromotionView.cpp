//
// Created by ismael on 1/11/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PawnPromotionView.h" resolved

#include "PawnPromotionView.h"
#include "ui_PawnPromotionView.h"

PawnPromotionView::PawnPromotionView(QWidget *parent, Coordinates coordinates) :
        QDialog(parent), ui(new Ui::PawnPromotionView), coordinates(coordinates) {
    ui->setupUi(this);
    // TODO: INVESTIGATE SETTING THE PROPER ACTION BUTTONS
    this->setWindowFlags(Qt::Dialog);
}

void PawnPromotionView::closeEvent(QCloseEvent *e) {
    PlayerID playerId = getPawnPlayerId();

    if (playerId == PlayerID::NONE) {
        this->reject();
    }

    ChessPiece* newChessPiecePtr = new Queen(playerId);
    promotePawn(newChessPiecePtr);
}

void PawnPromotionView::ButtonOnClick() {
    QObject* sourceObject = sender();
    QString qObjectName = sourceObject->objectName();
    std::string objectName = "";
    if (qObjectName != NULL) {
        objectName = qObjectName.toStdString();
    } else {
        this->reject();
    }

    PlayerID playerId = getPawnPlayerId();

    if (playerId == PlayerID::NONE) {
        this->reject();
    }

    ChessPiece* newChessPiecePtr = NULL;

    if (objectName == "QueenButton") {
        newChessPiecePtr = QueenOnClick(playerId);
    } else if (objectName == "RookButton") {
        newChessPiecePtr = RookOnClick(playerId);
    } else if (objectName == "BishopButton") {
        newChessPiecePtr = BishopOnClick(playerId);
    } else if (objectName == "KnightButton") {
        newChessPiecePtr = KnightOnClick(playerId);
    }

    promotePawn(newChessPiecePtr);
}

PlayerID PawnPromotionView::getPawnPlayerId() {
    ChessPiece* chessPiecePtr = ChessMovementUtils::getChessPieceAtIndex(coordinates.targetX, coordinates.targetY);
    PlayerID playerId = PlayerID::NONE;

    if (chessPiecePtr) {
        playerId = chessPiecePtr->getPlayerId();
    }

    return playerId;
}

void PawnPromotionView::promotePawn(ChessPiece* chessPiecePtr) {
    if (chessPiecePtr != NULL) {
        ChessMovementUtils::setChessPieceAtIndex(chessPiecePtr, coordinates.targetX, coordinates.targetY);
        this->accept();
    } else {
        this->reject();
    }
}

ChessPiece* PawnPromotionView::QueenOnClick(PlayerID playerId) {
    ChessPiece* chessPiece = new Queen(playerId);
    return chessPiece;
}

ChessPiece* PawnPromotionView::RookOnClick(PlayerID playerId) {
    ChessPiece* chessPiece = new Rook(playerId);
    return chessPiece;
}
ChessPiece* PawnPromotionView::BishopOnClick(PlayerID playerId) {
    ChessPiece* chessPiece = new Bishop(playerId);
    return chessPiece;
}

ChessPiece* PawnPromotionView::KnightOnClick(PlayerID playerId) {
    ChessPiece* chessPiece = new Knight(playerId);
    return chessPiece;
}

PawnPromotionView::~PawnPromotionView() {
    delete ui;
}

