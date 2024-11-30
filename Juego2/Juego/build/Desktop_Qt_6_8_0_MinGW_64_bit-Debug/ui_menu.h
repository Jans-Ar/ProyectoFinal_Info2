/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *btnN1;
    QPushButton *btnN2;
    QPushButton *btnSalir;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(600, 300);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName("centralwidget");
        btnN1 = new QPushButton(centralwidget);
        btnN1->setObjectName("btnN1");
        btnN1->setGeometry(QRect(230, 80, 75, 24));
        btnN2 = new QPushButton(centralwidget);
        btnN2->setObjectName("btnN2");
        btnN2->setGeometry(QRect(230, 110, 75, 24));
        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setGeometry(QRect(230, 140, 75, 24));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 50, 91, 16));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 22));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName("statusbar");
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "MainWindow", nullptr));
        btnN1->setText(QCoreApplication::translate("Menu", "Nivel 1", nullptr));
        btnN2->setText(QCoreApplication::translate("Menu", "Nivel 2", nullptr));
        btnSalir->setText(QCoreApplication::translate("Menu", "Salir", nullptr));
        label->setText(QCoreApplication::translate("Menu", "Men\303\272 Principal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
