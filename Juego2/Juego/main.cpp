#include "mainwindow.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.setWindowTitle("Homero King Size");

    w.show();
    return a.exec();
}
