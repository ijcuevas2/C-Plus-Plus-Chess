#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "ChessBoard/views/MainChessView/ChessView.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ChessView* chessView = new ChessView();
    chessView->show();
    return a.exec();
}
