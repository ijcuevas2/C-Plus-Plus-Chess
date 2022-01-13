//
// Created by ismael on 1/11/22.
//

#ifndef CHESS_PAWNPROMOTIONVIEW_H
#define CHESS_PAWNPROMOTIONVIEW_H

#include <QDialog>
#include "../../headers/Coordinates.h"
#include "../../headers/ChessPieces/ChessPiece.h"
#include "../../headers/ChessMovementUtils.h"
#include "../../headers/ChessPieces/Queen.h"
#include "../../headers/ChessPieces/Rook.h"
#include "../../headers/ChessPieces/Bishop.h"
#include "../../headers/ChessPieces/Knight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PawnPromotionView; }
QT_END_NAMESPACE

class PawnPromotionView : public QDialog {
Q_OBJECT

public:
    explicit PawnPromotionView(QWidget *parent = nullptr, Coordinates coordinates = Coordinates(0, 0, 0, 0));
    ~PawnPromotionView() override;
    void closeEvent(QCloseEvent* e);
public slots:
    // TODO: Check why a double click is required for moving the pawn
    void ButtonOnClick();
    void promotePawn(ChessPiece* chessPiecePtr);
    PlayerID getPawnPlayerId();
    ChessPiece* QueenOnClick(PlayerID playerId);
    ChessPiece* RookOnClick(PlayerID playerId);
    ChessPiece* BishopOnClick(PlayerID playerId);
    ChessPiece* KnightOnClick(PlayerID playerId);

private:
    Ui::PawnPromotionView *ui;
    Coordinates coordinates;
};


#endif //CHESS_PAWNPROMOTIONVIEW_H
