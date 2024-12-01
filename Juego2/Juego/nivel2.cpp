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

    this->generarMapa();

    tiempo = new QTimer;
    tiempo->start(40);
    connect(tiempo, &QTimer::timeout,
            this, &Nivel2::onUpdate);

    tDisparo = new QTimer;
    tDisparo->start(1000);
    connect(tDisparo, &QTimer::timeout,
            this, &Nivel2::dispararme);
}

Nivel2::~Nivel2()
{
    delete ui;
}

void Nivel2::onUpdate()
{
    if(Homero->getSalto()==true){
        Homero->saltar();
    }else if(Homero->getCaer()==true){
        Homero->caida();
    }else if(Homero->getTram()==true){
        Homero->trampolin();
    }

    if(Homero->getDisparar()==true){
        if(Homero->getDirS()==378){
            Proyectiles.append(new Proyectil(Homero->getX()+75,Homero->getY()+80, 'D'));
        }else if(Homero->getDirS()==504){
            Proyectiles.append(new Proyectil(Homero->getX()+30,Homero->getY()+80, 'I'));
        }
        Homero->confSprite(Homero->getDirS());
        escena->addItem(Proyectiles.last());
        Homero->setDisparar(false);
    }

    for (int i = 0; i < ProyectilesEnemigo.size(); i++) {
        Proyectil* BalasEnemy = ProyectilesEnemigo[i];
        BalasEnemy->trayectoria();
        if(BalasEnemy->getPx()>1300 || BalasEnemy->getPx()<0 ){
            escena->removeItem(BalasEnemy);
            ProyectilesEnemigo.removeOne(BalasEnemy);
        }

        QList<QGraphicsItem* >Cba = escena->collidingItems(BalasEnemy);
        if(!Cba.isEmpty()){
            for(auto c : Cba){
                Jugador *e = dynamic_cast<Jugador *>(c);
                if(e){
                    escena->removeItem(BalasEnemy);
                    Proyectiles.removeOne(BalasEnemy);
                    Homero->setMove(false);
                    if(Homero->getDirS()==0){
                        Homero->setCont(0);
                    }else if(Homero->getDirS()==126){
                        Homero->setCont(3);
                    }
                    Homero->setDirS(635);
                    Homero->confSprite(Homero->getDirS());
                    tDisparo->stop();
                    continue;
                }
            }
        }

    }

    for (int i = 0; i < Proyectiles.size(); i++) {
        Proyectil* misBalas = Proyectiles[i];
        misBalas->trayectoria();
        if(misBalas->getPx()>1300 || misBalas->getPx()<0 ){
            escena->removeItem(misBalas);
            Proyectiles.removeOne(misBalas);
        }

        QList<QGraphicsItem* >Cba = escena->collidingItems(misBalas);
        if(!Cba.isEmpty()){
            for(auto c : Cba){
                Enemy *e = dynamic_cast<Enemy *>(c);
                if(e){
                    escena->removeItem(Enemigo);
                    escena->removeItem(misBalas);
                    Proyectiles.removeOne(misBalas);
                    tDisparo->stop();
                    //delete Enemigo;
                    //Enemigo = nullptr;
                    continue;
                }
            }
        }

    }


    Enemigo->moverse();


    Colisiones = escena->collidingItems(Homero);
    if(!Colisiones.isEmpty()){
        for(auto c : Colisiones){
            Bloque *bloques = dynamic_cast<Bloque *>(c);
            if(bloques){

                if(Homero->getY()<= bloques->getBpy()-90 && bloques->getTipo()==fijo){
                    Homero->setVy(0);
                    Homero->setLInf(bloques->getBpy()-2);
                    Homero->setLSup(bloques->getBpy()-80);
                    Homero->setSalto(false);
                    Homero->setCaer(false);
                    Homero->setY(Homero->getY()-1);
                    Homero->setPos(Homero->getX(),Homero->getY());
                    Homero->setCont(0);
                    Homero->confSprite(Homero->getDirS());
                }else if(Homero->getY()>=bloques->getBpy() && bloques->getTipo()==fijo){
                    Homero->setCaer(true);
                    Homero->setSalto(false);
                }else if(bloques->getTipo()==puerta){
                    this->close();
                }


            }
        }
    }

    if((Homero->getX() >= Homero->getLd()) && Homero->getY()<=600){
        Homero->setVy(30);
    }else if((Homero->getX() <= Homero->getLi()) && Homero->getY()<=270 ){
        Homero->setVy(30);
    }

    for (int i = 0; i < Pendulos.size(); i++) {
        PenduloSimple* pendu = Pendulos[i];
        QList<QGraphicsItem* >Cp = escena->collidingItems(pendu);
        if(!Cp.isEmpty()){
            for(auto c : Cp){
                Jugador *pj2 = dynamic_cast<Jugador *>(c);
                if(pj2){
                    Homero->setMove(false);
                    if(Homero->getDirS()==0){
                        Homero->setCont(0);
                    }else if(Homero->getDirS()==126){
                        Homero->setCont(3);
                    }
                    Homero->setDirS(635);
                    Homero->confSprite(Homero->getDirS());
                    continue;
                }
            }
        }
    }

    for (int i = 0; i < Trampolines.size(); i++) {
        Trampolin* trampo = Trampolines[i];
        QList<QGraphicsItem* >Ct = escena->collidingItems(trampo);
        if(!Ct.isEmpty()){
            for(auto c : Ct){
                Jugador *pj = dynamic_cast<Jugador *>(c);
                if(pj){
                    if(Homero->getMove()==true && Homero->getSalto()==false && Homero->getTram()==false){
                        Homero->setMove(false);
                    }else if(Homero->getSalto()==true){
                        if(Homero->getDirS()==0){
                            Homero->setCont(0);
                        }else if(Homero->getDirS()==126){
                            Homero->setCont(3);
                        }
                        Homero->setMove(true);
                        Homero->confSprite(252);
                        Homero->setTram(true);
                        Homero->setSalto(false);
                        Homero->setCaer(false);
                        Homero->setLInf(trampo->getPy());
                    }else if(Homero->getCaer()==true){
                        if(Homero->getDirS()==0){
                            Homero->setCont(0);
                        }else if(Homero->getDirS()==126){
                            Homero->setCont(3);
                        }
                        Homero->setMove(true);
                        Homero->confSprite(252);
                        Homero->setTram(true);
                        Homero->setSalto(false);
                        Homero->setCaer(false);
                        Homero->setLInf(trampo->getPy());
                    }
                    continue;
                }
            }
        }
    }
    if(Homero->getY()<=600 && Homero->getSalto()==false && Homero->getTram()==false){
        Homero->setLInf(630);
        if(Homero->getSalto()==false){
            Homero->setCaer(true);
        }
    }
    //qDebug()<<Homero->getX();
    // qDebug()<<Homero->getY();
    //qDebug() << Homero->getLd();
}

void Nivel2::generarMapa()
{
    Enemigo = new Enemy;
    escena -> addItem(Enemigo);
    Enemigo->setX(700);
    Enemigo->setY(142.5);
    Enemigo->setPos(700,142.5);
    Enemigo->setDirS(400);
    Enemigo->setCont(0);
    Enemigo->setDirA(Enemigo->getDirS());
    Enemigo->confSprites(Enemigo->getDirS());

    //PenduloSimple* pendulo = new PenduloSimple(220, 0.7, 500,300); // Longitud = 100, ángulo inicial = 0.5 rad
    //escena->addItem(pendulo);


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
            else if(Matriz[i][j]=='4'){
                Matriz[i][j] = fijo;
                if(Homero->getLd()==0){
                    Homero->setLd(j*30);
                }else{
                    Homero->setLi(j*30);
                }

                qDebug() << j*30;
                qDebug() << i*30;
            }
            else if(Matriz[i][j]=='1'){
                Matriz[i][j] = destructible;
            }
            else if(Matriz[i][j]==char(32) || Matriz[i][j]==char(47)){
                Matriz[i][j] = vacio;
            }else if(Matriz[i][j]=='3'){
                Matriz[i][j] = trampolin;
            }else if(Matriz[i][j]=='5'){
                Matriz[i][j] = puerta;
            }
        }
        i+=1;
    }

    float aux;

    if(Homero->getLd()<Homero->getLi()){
        aux=Homero->getLd();
        Homero->setLd(Homero->getLi());
        Homero->setLi(aux);
    }

    Homero->setLi(Homero->getLi()-60);
    MyReadFile.close();

    Bloques.clear();

    for(int i=0 ; i<30 ; i++){
        for(int j=0 ; j<50 ; j++){
            if(Matriz[i][j]!=vacio && Matriz[i][j]!=trampolin){
                //Bloque *b=new Bloque();
                Bloques.append(new Bloque(j*30,i*30,Matriz[i][j]));
                escena->addItem(Bloques.last());
            }else if(Matriz[i][j]==trampolin){
                Trampolines.append(new Trampolin(j*30,i*30));
                escena->addItem(Trampolines.last());
            }
        }
    }

    Pendulos.append(new PenduloSimple(185, 0.7,500,300));
    escena->addItem(Pendulos.last());
    Pendulos.append(new PenduloSimple(185, 0.7,800,300));
    escena->addItem(Pendulos.last());
    //qDebug()<< Pendulos.size();

    lSup=550;
    lInf=630;
}

void Nivel2::dispararme()
{
    if(Homero->getY()<=170){
        Enemigo->setMove(false);
        Enemigo->setDirA(Enemigo->getDirS());
        ProyectilesEnemigo.append(new Proyectil(Enemigo->getX()+5,Enemigo->getY()+45, 'I'));
        Enemigo->setCont(2);
        Enemigo->setDirS(136);
        Enemigo->confSprite(Enemigo->getDirS());
        escena->addItem(ProyectilesEnemigo.last());
    }else{
        if(Enemigo->getMove()==false){
            Enemigo->setMove(true);
            Enemigo->setDirS(Enemigo->getDirA());
        }
    }
}
