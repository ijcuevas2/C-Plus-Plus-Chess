//
// Created by ismael on 10/16/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ChessView.h" resolved

#include "ChessView.h"
#include "ui_ChessView.h"
#include "../../headers/Game.h"
#include "../../headers/ChessMovementUtils.h"
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
            QList<QObject*> children = boardSpace->children();
            scene->addItem(boardSpace);
        }
    }

    graphicsView->setScene(scene);

    QLabel* turnLabel = findChild<QLabel*>("turnLabel");
    if (turnLabel != NULL) {
        ChessMovementUtils::setLabelPtr(turnLabel);
        turnLabel->setText("Current Turn (Light Turn): 1");
    }

    QLabel* kingInCheckLabel = findChild<QLabel*>("KingInCheckLabel");
    if (kingInCheckLabel != NULL) {
        ChessMovementUtils::setLabelPtr(kingInCheckLabel);
        kingInCheckLabel->setText("");
    }

    if (game != NULL) {
        ChessMovementUtils::setGamePtr(game);
    }
}

void ChessView::keyPressEvent(QKeyEvent* k) {
    switch (k->key()) {
        case Qt::Key_Escape:
            ChessMovementUtils::clearBoardSpaceList();
            break;
    }
}

ChessView::~ChessView() {
    delete ui;
}

