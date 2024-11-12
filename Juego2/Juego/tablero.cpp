#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) : QMainWindow(parent) , ui(new Ui::Tablero)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,600,600);
    scene->setBackgroundBrush(QBrush(QImage(":/Sprites/sad.jpg")));
    ui->graphicsView->setScene(scene);

    p1 = nullptr;

    connect(ui->pB_start, &QPushButton::clicked,
            this, &Tablero::onStart);
}

Tablero::~Tablero()
{
    delete ui;
}

void Tablero::keyPressEvent(QKeyEvent *event)
{
    if(p1!=nullptr){
        if(event->key()==Qt::Key_A){
            p1->setVx(-20);
            p1->setVy(0);
        }else if(event->key()==Qt::Key_D){
            p1->setVx(20);
            p1->setVy(0);
        }else if(event->key()==Qt::Key_W){
            p1->setVy(-20);
            p1->setVx(0);
        }else if(event->key()==Qt::Key_S){
            p1->setVy(20);
            p1->setVx(0);
        }else if(event->key()==Qt::Key_P){
            auto p = p1->disparar();
            if(p!=nullptr){
                scene->addItem(p);
                connect(p,&Proyectil::finProyectil,
                        this,&Tablero::eliminarProyectil);
            }
        }else if(event->key()==Qt::Key_Space){
            p1->setVx(0);
            p1->setVy(0);
        }
    }
}

void Tablero::onStart()
{
    p1 = new Personaje;
    scene->addItem(p1);

    crearMapa();

    tiempo = new QTimer;
    tiempo->start(100);

    QGraphicsLineItem linea(0,0,400,400);
    scene->addItem(&linea);

    connect(tiempo, &QTimer::timeout,
            this, &Tablero::onUpdate);

    ui->pB_start->hide();
}

void Tablero::onUpdate(){
    scene->advance();

    if(Galletas.size()<6){
        Galletas.push_back(new Galleta(rand()%540,0));
        scene->addItem(Galletas.last());
    }

    QList<QGraphicsItem*> Colisiones = scene->collidingItems(p1);
    if(!Colisiones.isEmpty()){
        //qDebug()<<"Colision";
        for(auto c : Colisiones){
            Muro *muro = dynamic_cast<Muro *>(c);
            if(muro){
                qDebug()<<"Muro";
                p1->setVx(0);
                p1->setVy(0);
            }

            Proyectil *proyectil = dynamic_cast<Proyectil *>(c);
            if(proyectil){
                qDebug()<<"Proyectil";
            }

            Galleta *galleta = dynamic_cast<Galleta *>(c);
            if(galleta){
                scene->removeItem(galleta);
                Galletas.removeOne(galleta);
                qDebug()<<"Galletas: "<<Galletas.size();

            }

            QGraphicsLineItem *puerta = dynamic_cast<QGraphicsLineItem *>(c);
            if(puerta){
                if(puerta==puerta1)
                    p1->setPx(530);
                else {
                    p1->setPx(30);
                }

            }
        }
    }

    for (int i = 0; i < Galletas.size(); ++i) {
        Galleta* galleta = Galletas[i];
        galleta->setPy(galleta->getPy()+10);
        galleta->setPos(galleta->getPx(),galleta->getPy());
        if(galleta->getPy()>580){
            scene->removeItem(galleta);
            Galletas.removeOne(galleta);
             //Galletas.removeAt(i);
        }
    }

}

void Tablero::eliminarProyectil()
{
    auto p = p1->eliminarProyectil();
    scene->removeItem(p);
}


void Tablero::crearMapa(){
    // Algortimo logico => ciclo, archivo, random
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(i<5 && j<5){
                Mapa[i][j] = 0;
                continue;
            }

            if(i%2==1 && j%2==1){
                Mapa[i][j]=1;
            }else{
                Mapa[i][j]=2;
            }
        }
    }

    puerta1 = new QGraphicsLineItem(0,510,0,540);
    scene->addItem(puerta1);

    puerta2 = new QGraphicsLineItem(590,510,590,540);
    scene->addItem(puerta2);

    // Parte grafico
    for(int i=0; i<20; i++){
        Muros.push_back(new Muro(i*30,570));
        scene->addItem(Muros.last());
    }
}











