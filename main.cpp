#include <QApplication>
#include <QPushButton>
#include "ChessBoard/headers/Board.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();

    Board* board = new Board();
    board->initializeBoard();
    board->printBoard();

    return QApplication::exec();
}
