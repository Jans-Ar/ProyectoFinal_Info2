#ifndef MENU_H
#define MENU_H

#include "mainwindow.h"


#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

public slots:
   void abrirNivel1();
   void abrirNivel2();
   void closeGame();

private:
    Ui::Menu *ui;

    MainWindow *N1;
    Nivel2 *N2;
};

#endif // MENU_H
