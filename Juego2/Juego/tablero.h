#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QList>

#include "personaje.h"
#include "muro.h"
#include "galleta.h"
#include "proyectil.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Tablero; }
QT_END_NAMESPACE

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    Tablero(QWidget *parent = nullptr);
    ~Tablero();
    void keyPressEvent(QKeyEvent *event);

    void crearMapa(void);

public slots:
    void onStart(void);
    void eliminarProyectil(void);
    void onUpdate();

private:
    Ui::Tablero     *ui;
    QGraphicsScene  *scene;
    QTimer          *tiempo;

    Personaje *p1;
    int Mapa[20][20];
    QVector<Muro *> Muros;
    QVector<Galleta *> Galletas;

    QGraphicsLineItem *puerta1;
    QGraphicsLineItem *puerta2;

};
#endif // TABLERO_H








