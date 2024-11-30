/********************************************************************************
** Form generated from reading UI file 'nivel2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL2_H
#define UI_NIVEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Nivel2
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Nivel2)
    {
        if (Nivel2->objectName().isEmpty())
            Nivel2->setObjectName("Nivel2");
        Nivel2->resize(1400, 800);
        centralwidget = new QWidget(Nivel2);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 1350, 770));
        Nivel2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Nivel2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 22));
        Nivel2->setMenuBar(menubar);
        statusbar = new QStatusBar(Nivel2);
        statusbar->setObjectName("statusbar");
        Nivel2->setStatusBar(statusbar);

        retranslateUi(Nivel2);

        QMetaObject::connectSlotsByName(Nivel2);
    } // setupUi

    void retranslateUi(QMainWindow *Nivel2)
    {
        Nivel2->setWindowTitle(QCoreApplication::translate("Nivel2", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nivel2: public Ui_Nivel2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL2_H
