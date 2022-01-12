//
// Created by ismael on 1/11/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PawnPromotionView.h" resolved

#include <iostream>
#include "PawnPromotionView.h"
#include "ui_PawnPromotionView.h"


PawnPromotionView::PawnPromotionView(QWidget *parent) :
        QDialog(parent), ui(new Ui::PawnPromotionView) {
    ui->setupUi(this);
    // TODO: INVESTIGATE SETTING THE PROPER ACTION BUTTONS
    this->setWindowFlags(Qt::Dialog );
    std::cout << "Init Pawn Promotion View" << std::endl;
}

void PawnPromotionView::mousePressEvent(QMouseEvent *event) {
    std::cout << "Mouse Pressed!!" << std::endl;
}

void PawnPromotionView::closeEvent(QCloseEvent *e) {
    std::cout << "Window Closed!!" << std::endl;
}

PawnPromotionView::~PawnPromotionView() {
    delete ui;
}

