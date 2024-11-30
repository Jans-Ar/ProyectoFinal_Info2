#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,1500,900);
    escena->setBackgroundBrush(QBrush(QImage(":/springfield (2).png")));
    ui->graphicsView->setScene(escena);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
    ui->graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);

    Homero = new Jugador;
    escena -> addItem(Homero);
    Homero -> setPos(0,630);

    this->generarMapa();

    tiempo = new QTimer;
    tiempo->start(40);
    connect(tiempo, &QTimer::timeout,
        this, &Nivel2::onUpdate);
}

Nivel2::~Nivel2()
{
    delete ui;
}

void Nivel2::onUpdate()
{
    if(Homero->getSalto()==true){
        Homero->saltar();
    }

    if(Homero->getCaer()==true){
        Homero->caida();
    }


    Colisiones = escena->collidingItems(Homero);
    if(!Colisiones.isEmpty()){
        for(auto c : Colisiones){
            Bloque *bloques = dynamic_cast<Bloque *>(c);
            if(bloques){

                if(Homero->getY()<=bloques->getBpy()){
                    Homero->setVy(0);
                    Homero->setLInf(bloques->getBpy());
                    Homero->setLSup(bloques->getBpy()-80);
                    Homero->setSalto(false);
                    Homero->setCaer(false);
                    Homero->setY(bloques->getBpy()-126);
                    Homero->setPos(Homero->getX(),Homero->getY());

                    Homero->setCont(0);
                    Homero->confSprite(Homero->getDirS());
                }else if(Homero->getY()>=bloques->getBpy()){
                    Homero->setCaer(true);
                    Homero->setSalto(false);
                }
            }
        }
    }
    if(Homero->getY()<=600 && Homero->getSalto()==false){
        Homero->setLInf(630);
        if(Homero->getSalto()==false){
            Homero->setCaer(true);
        }
    }
    qDebug()<<Homero->getX();
    qDebug()<<Homero->getY();
}

void Nivel2::generarMapa()
{
    string myText = "mapa.txt";
    ifstream MyReadFile("mapa.txt");

    for(int i=0 ; i<30 ; i++){//limpiar matriz
        for(int j=0 ; j<50 ; j++){
            Matriz[i][j] = vacio;
        }
    }

    int i=0;
    while (getline (MyReadFile, myText)) {
        for(int j=0 ; j<int(myText.size()) ; j++){
            Matriz[i][j]=myText[j];

            if(Matriz[i][j]=='0'){
                Matriz[i][j] = fijo;
            }
            else if(Matriz[i][j]=='1'){
                Matriz[i][j] = destructible;
            }
            else if(Matriz[i][j]==char(32) || Matriz[i][j]==char(47)){
                Matriz[i][j] = vacio;
            }
        }
        i+=1;
    }
    MyReadFile.close();

    Bloques.clear();

    for(int i=0 ; i<30 ; i++){
        for(int j=0 ; j<50 ; j++){
            if(Matriz[i][j]!=vacio){
                //Bloque *b=new Bloque();
                Bloques.append(new Bloque(j*30,i*30,Matriz[i][j]));
                escena->addItem(Bloques.last());
            }
        }
    }

    lSup=550;
    lInf=630;
}
