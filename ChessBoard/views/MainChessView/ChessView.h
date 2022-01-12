//
// Created by ismael on 10/16/21.
//

#ifndef CHESS_CHESSVIEW_H
#define CHESS_CHESSVIEW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class ChessView; }
QT_END_NAMESPACE

class ChessView : public QMainWindow {
Q_OBJECT

public:
    explicit ChessView(QWidget *parent = nullptr);
    void setupScene();
    ~ChessView() override;
    void keyPressEvent(QKeyEvent* k);
private:
    Ui::ChessView *ui;
};


#endif //CHESS_CHESSVIEW_H
