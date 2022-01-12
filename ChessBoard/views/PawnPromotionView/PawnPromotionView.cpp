//
// Created by ismael on 1/11/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PawnPromotionView.h" resolved

#include "PawnPromotionView.h"
#include "ui_PawnPromotionView.h"


PawnPromotionView::PawnPromotionView(QWidget *parent) :
        QDialog(parent), ui(new Ui::PawnPromotionView) {
    ui->setupUi(this);
    // TODO: INVESTIGATE SETTING THE PROPER ACTION BUTTONS
    this->setWindowFlags(Qt::Dialog );
    setupListeners();
}

void PawnPromotionView::setupListeners() {
    QPushButton* button = findChild<QPushButton*>("Queen");
//    button->
}

PawnPromotionView::~PawnPromotionView() {
    delete ui;
}

