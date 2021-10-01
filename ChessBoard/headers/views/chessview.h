//
// Created by ismael on 10/1/21.
//

#ifndef CHESS_CHESSVIEW_H
#define CHESS_CHESSVIEW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class chessview; }
QT_END_NAMESPACE

class chessview : public QWidget {
Q_OBJECT

public:
    explicit chessview(QWidget *parent = nullptr);

    ~chessview() override;

private:
    Ui::chessview *ui;
};


#endif //CHESS_CHESSVIEW_H
