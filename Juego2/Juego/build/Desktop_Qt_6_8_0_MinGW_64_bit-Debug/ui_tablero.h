/********************************************************************************
** Form generated from reading UI file 'tablero.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLERO_H
#define UI_TABLERO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tablero
{
public:
    QWidget *centralwidget;
    QLabel *lb_titulo;
    QPushButton *pB_start;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Tablero)
    {
        if (Tablero->objectName().isEmpty())
            Tablero->setObjectName("Tablero");
        Tablero->resize(725, 800);
        centralwidget = new QWidget(Tablero);
        centralwidget->setObjectName("centralwidget");
        lb_titulo = new QLabel(centralwidget);
        lb_titulo->setObjectName("lb_titulo");
        lb_titulo->setGeometry(QRect(300, 20, 141, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        lb_titulo->setFont(font);
        pB_start = new QPushButton(centralwidget);
        pB_start->setObjectName("pB_start");
        pB_start->setGeometry(QRect(460, 30, 75, 24));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(60, 70, 630, 630));
        Tablero->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tablero);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 725, 22));
        Tablero->setMenuBar(menubar);
        statusbar = new QStatusBar(Tablero);
        statusbar->setObjectName("statusbar");
        Tablero->setStatusBar(statusbar);

        retranslateUi(Tablero);

        QMetaObject::connectSlotsByName(Tablero);
    } // setupUi

    void retranslateUi(QMainWindow *Tablero)
    {
        Tablero->setWindowTitle(QCoreApplication::translate("Tablero", "Tablero", nullptr));
        lb_titulo->setText(QCoreApplication::translate("Tablero", "Los Simpsons", nullptr));
        pB_start->setText(QCoreApplication::translate("Tablero", "Comenzar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tablero: public Ui_Tablero {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLERO_H
