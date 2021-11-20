//
// Created by ismael on 10/16/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChessView.h" resolved

#include "ChessView.h"
#include "ui_ChessView.h"
#include "../headers/Game.h"
#include "../headers/ChessMovementMediator.h"
#include <QFile>

ChessView::ChessView(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::ChessView) {
    ui->setupUi(this);
    setupScene();
}

void ChessView::setupScene() {
    Game* game = new Game();
    // TODO: Add NULL checks
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

    QLabel* qLabel = findChild<QLabel*>("turnLabel");
    if (qLabel != NULL) {
        ChessMovementMediator::setLabelPtr(qLabel);
        qLabel->setText("Current Turn (Light Turn): 1");
    }

    if (game != NULL) {
        ChessMovementMediator::setGamePtr(game);
    }
}



ChessView::~ChessView() {
    delete ui;
}

