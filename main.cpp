#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "ChessBoard/headers/Game.h"
#include "ChessBoard/views/ChessView.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ChessView* chessView = new ChessView();
    chessView->show();
    return a.exec();
}
