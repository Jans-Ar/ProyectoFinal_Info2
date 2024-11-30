#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->btnN1, &QPushButton::clicked, this, &Menu::abrirNivel1);
    connect(ui->btnN2, &QPushButton::clicked, this, &Menu::abrirNivel2);
    connect(ui->btnSalir, &QPushButton::clicked, this, &Menu::closeGame);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::abrirNivel1()
{
    N1 = new MainWindow();
    N1->setWindowTitle("Nivel 1");
    N1->show();
}

void Menu::abrirNivel2()
{
    N2 = new Nivel2();
    N2->setWindowTitle("Nivel 2");
    N2->show();
}

void Menu::closeGame()
{
    this->close();
}
