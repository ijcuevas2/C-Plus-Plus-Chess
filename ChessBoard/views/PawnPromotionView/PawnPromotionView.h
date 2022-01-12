//
// Created by ismael on 1/11/22.
//

#ifndef CHESS_PAWNPROMOTIONVIEW_H
#define CHESS_PAWNPROMOTIONVIEW_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class PawnPromotionView; }
QT_END_NAMESPACE

class PawnPromotionView : public QDialog {
Q_OBJECT

public:
    explicit PawnPromotionView(QWidget *parent = nullptr);
    ~PawnPromotionView() override;
    void mousePressEvent(QMouseEvent* event);
    void closeEvent(QCloseEvent* e);
private:
    Ui::PawnPromotionView *ui;
};


#endif //CHESS_PAWNPROMOTIONVIEW_H
