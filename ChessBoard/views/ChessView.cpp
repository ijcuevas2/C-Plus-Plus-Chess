//
// Created by ismael on 10/16/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChessView.h" resolved

#include "ChessView.h"
#include "ui_ChessView.h"
#include "../headers/Game.h"
#include <QFile>

ChessView::ChessView(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ChessView) {
    ui->setupUi(this);
    setupScene();
}

void ChessView::setupScene() {
    Game* game = new Game();
    QGraphicsView* graphicsView = findChild<QGraphicsView*>("graphicsView");
    std::vector<std::vector<BoardSpace*>> board = game->getBoard();
    QGraphicsScene* scene = new QGraphicsScene(0, 0, 600, 600);

    for (std::vector<BoardSpace*> boardSpaceList : board) {
        for (BoardSpace* boardSpace : boardSpaceList) {
            auto children = boardSpace->children();
            scene->addItem(boardSpace);
        }
    }

    graphicsView->setScene(scene);
}

ChessView::~ChessView() {
    delete ui;
}

