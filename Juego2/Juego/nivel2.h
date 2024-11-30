#ifndef NIVEL2_H
#define NIVEL2_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QList>
#include "jugador.h"
#include "galleta.h"
#include "saludables.h"
#include "score.h"
#include "tiempo.h"
#include "bloque.h"
#include <iostream>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui {
class Nivel2;
}
QT_END_NAMESPACE

class Nivel2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = nullptr);
    ~Nivel2();
public slots:
    void onUpdate();
    void generarMapa();

private:
    Ui::Nivel2 *ui;
    QGraphicsScene *escena;
    QList<QGraphicsItem* >Colisiones;
    Jugador *Homero;
    QTimer *tiempo;

    int Matriz[30][50];
    QVector<Bloque *> Bloques;

    int lInf;
    int lSup;

};

#endif // NIVEL2_H
