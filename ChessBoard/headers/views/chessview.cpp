//
// Created by ismael on 10/1/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_chessview.h" resolved

#include "chessview.h"
#include "ui_chessview.h"


chessview::chessview(QWidget *parent) :
        QWidget(parent), ui(new Ui::chessview) {
    ui->setupUi(this);
}

chessview::~chessview() {
    delete ui;
}

