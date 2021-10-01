/********************************************************************************
** Form generated from reading UI file 'chessview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSVIEW_H
#define UI_CHESSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessview
{
public:

    void setupUi(QWidget *chessview)
    {
        if (chessview->objectName().isEmpty())
            chessview->setObjectName(QString::fromUtf8("chessview"));
        chessview->resize(400, 300);

        retranslateUi(chessview);

        QMetaObject::connectSlotsByName(chessview);
    } // setupUi

    void retranslateUi(QWidget *chessview)
    {
        chessview->setWindowTitle(QApplication::translate("chessview", "chessview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chessview: public Ui_chessview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSVIEW_H
