#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "ChessBoard/views/MainChessView/ChessView.h"
#include "ChessBoard/headers/ChessMovementUtils.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ChessView* chessView = new ChessView();
    ChessMovementUtils::setChessViewPtr(chessView);
    chessView->show();
    return a.exec();
}
