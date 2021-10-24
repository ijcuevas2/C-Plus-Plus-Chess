#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "ChessBoard/headers/Game.h"
#include "ChessBoard/views/ChessView.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    Game* board = new Game();
//    board->printBoard();
//    delete board;

    // create a scene
//    QGraphicsScene* scene = new QGraphicsScene();

//    QGraphicsRectItem* rect = new QGraphicsRectItem();
//    rect->setRect(0, 0, 100, 100);

    // add the item to the scene
    // scene->addItem(rect);

    ChessView* chessView = new ChessView();
    chessView->show();
    return a.exec();
}
