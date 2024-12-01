#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jugador.h"
#include "saludables.h"
#include <Qdebug>
#include <QGraphicsView>
#include <QScreen>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,1500,900);
    escena->setBackgroundBrush(QBrush(QImage(":/CasaHomero9bit.png")));
    ui->graphicsView->setScene(escena);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
    ui->graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);

    //connect(ui->pB_start, &QPushButton::clicked,
    //        this, &Tablero::onStart);

    //ui->graphicsView->setScene(escena);
    Homero = new Jugador;
    escena -> addItem(Homero);

    tiempo = new QTimer;
    tiempo->start(40);
    connect(tiempo, &QTimer::timeout,
        this, &MainWindow::onUpdate);

    timeGalletas = new QTimer();
    timeGalletas->start(2000);

    connect(timeGalletas, &QTimer::timeout, this, &MainWindow::generarGalletas);

    tPartida = new QTimer();
    tPartida->start(1000);

    connect(tPartida, &QTimer::timeout, this, &MainWindow::reducirTiempo);


    puerta1 = new QGraphicsLineItem(10,650,10,750);
    escena->addItem(puerta1);

    puerta2 = new QGraphicsLineItem(1340,650,1340,750);
    escena->addItem(puerta2);

    velGalletas=10;

    score = new Score();
    escena->addItem(score);


    miT = new Tiempo();
    escena->addItem(miT);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onUpdate()
{


    if(Homero->getSalto()==true){
        Homero->saltar();
    }

    Colisiones = escena->collidingItems(Homero);
    if(!Colisiones.isEmpty()){
        for(auto c : Colisiones){
            Galleta *galleta = dynamic_cast<Galleta *>(c);
            //saludables *salud = dynamic_cast<saludables *>(c);
            if(galleta){
                escena->removeItem(galleta);
                Galletas.removeOne(galleta);
                qDebug()<<"Galletas: "<<Galletas.size();
                score->increase();

            }

            QGraphicsLineItem *puerta = dynamic_cast<QGraphicsLineItem *>(c);
            if(puerta){
                if(puerta==puerta1){
                    Homero->setX(1200);
                    Homero->setPos(1200,630);
                }
                else{
                    Homero->setX(10);
                    Homero->setPos(10,630);
                }
            }
        }
    }



    for (int i = 0; i < Galletas.size(); i++) {
        Galleta* galleta = Galletas[i];
        galleta->advance(velGalletas);
        if(galleta->getPy()>750){
            escena->removeItem(galleta);
            Galletas.removeOne(galleta);
        }
    }

    for (int i = 0; i < saludable.size(); i++) {
        saludables* salud = saludable[i];
        salud->advance(velGalletas);
        if(salud->getPy()>750){
            escena->removeItem(salud);
            saludable.removeOne(salud);
        }

        QList<QGraphicsItem* >Cf1 = escena->collidingItems(salud);
        if(!Cf1.isEmpty()){
            for(auto c : Cf1){
                Jugador *pj = dynamic_cast<Jugador *>(c);
                if(pj){
                    escena->removeItem(salud);
                    saludable.removeOne(salud);
                    qDebug()<<"ss: "<<saludable.size();
                    score->decrease();
                    continue;
                }
            }
        }

    }

}

void MainWindow::generarGalletas()
{
    if(miT->getTiempo()>0){
        if(rand()%2==0){
            Galletas.push_back(new Galleta());
            escena->addItem(Galletas.last());
        }else{
            saludable.push_back(new saludables());
            escena->addItem(saludable.last());
        }

        velGalletas+=0.7;
    }
}

void MainWindow::reducirTiempo()
{
    miT->reducirT();
    if(miT->getTiempo()==0){
        Homero->setMove(false);
        if(score->getscore()>=1){
            miT->win();

            N2 = new Nivel2();
            N2->setWindowTitle("Nivel 2");
            N2->show();
            tPartida->stop();

            // Cerrar la ventana actual
            this->close();

        }else{
            miT->gameOver();
        }

    }
}



