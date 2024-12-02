#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "nivel2.h"

#include <QMediaPlayer>
#include <QUrl>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void keyPressEvent(QKeyEvent *event)override;

public slots:
    void onUpdate();
    void generarGalletas();
    void reducirTiempo();

private:
    Ui::MainWindow *ui;
    QTimer *tiempo;
    QTimer *timeGalletas;
    QTimer *tPartida;

    Jugador *Homero;
    QGraphicsScene *escena;
    QList<QGraphicsItem* >Colisiones;

    QVector<Galleta *> Galletas;
    QVector<saludables *> saludable;
    int velGalletas;
    QGraphicsLineItem *puerta1;
    QGraphicsLineItem *puerta2;

    Score *score;
    Tiempo *miT;


    Nivel2 *N2;

    QMediaPlayer* musicaFondo;
    QAudioOutput* volumen;
};
#endif // MAINWINDOW_H
