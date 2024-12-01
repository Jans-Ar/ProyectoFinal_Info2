#include "jugador.h"
#include <QKeyEvent>


float Jugador::getVx() const
{
    return vx;
}

void Jugador::setVx(float newVx)
{
    vx = newVx;
}

float Jugador::getVy() const
{
    return vy;
}

void Jugador::setVy(float newVy)
{
    vy = newVy;
}

float Jugador::getAx() const
{
    return ax;
}

void Jugador::setAx(float newAx)
{
    ax = newAx;
}

float Jugador::getAy() const
{
    return ay;
}

void Jugador::setAy(float newAy)
{
    ay = newAy;
}

bool Jugador::getSalto() const
{
    return salto;
}

void Jugador::setSalto(bool newSalto)
{
    salto = newSalto;
}

qreal Jugador::getY() const
{
    return y;
}

void Jugador::setY(qreal newY)
{
    y = newY;
}

qreal Jugador::getX() const
{
    return x;
}

void Jugador::setX(qreal newX)
{
    x = newX;
}

float Jugador::getT() const
{
    return t;
}

void Jugador::setT(float newT)
{
    t = newT;
}

bool Jugador::getMove() const
{
    return move;
}

void Jugador::setMove(bool newMove)
{
    move = newMove;
}

bool Jugador::getCaer() const
{
    return caer;
}

void Jugador::setCaer(bool newCaer)
{
    caer = newCaer;
}

int Jugador::getCont() const
{
    return cont;
}

void Jugador::setCont(int newCont)
{
    cont = newCont;
}

int Jugador::getDirS() const
{
    return dirS;
}

void Jugador::setDirS(int newDirS)
{
    dirS = newDirS;
}


bool Jugador::getTram() const
{
    return tram;
}

void Jugador::setTram(bool newTram)
{
    tram = newTram;
}

bool Jugador::getDisparar() const
{
    return disparar;
}

void Jugador::setDisparar(bool newDisparar)
{
    disparar = newDisparar;
}

float Jugador::getLInf() const
{
    return lInf;
}

void Jugador::setLInf(float newLInf)
{
    lInf = newLInf;
}

float Jugador::getLSup() const
{
    return lSup;
}

void Jugador::setLSup(float newLSup)
{
    lSup = newLSup;
}

float Jugador::getLd() const
{
    return ld;
}

void Jugador::setLd(float newLd)
{
    ld = newLd;
}

float Jugador::getLi() const
{
    return li;
}

void Jugador::setLi(float newLi)
{
    li = newLi;
}

Jugador::Jugador() {
    x=0;
    y=630;

    //x=400;
    //y=120;
    spriteX = 0;
    spriteY = 0;
    spriteAncho = 129;
    spriteAlto = 126;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/Homero2.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    move = true;

    lInf=630;
    lSup=550;

    li=0;
    ld=0;

    salto=false;
    caer=false;
    disparar=false;
    setPos(x,y);
    cont=0;
}

void Jugador::keyPressEvent(QKeyEvent * evento){
    if(move==true){
        switch(evento->key()){
        case Qt::Key_A:
            if(salto!=true && x>-30){
                dirS=126;
                movimiento(-15,0);
                confSprite(dirS);
                vx=-25;
            }
            break;
        case Qt::Key_D:
            if(salto!=true && x<1250){
                dirS = 0;
                movimiento(15,0);
                confSprite(dirS);
                vx=25;
            }
            break;
        case Qt::Key_W:
            //movimiento(vx,-15);
            if(salto!=true && tram!=true){
                t=0;
                salto=true;
                caer=false;
                if(dirS==0){
                    cont=0;
                }else if(dirS==126 && tram==false){
                    cont=3;
                }
                vy=25;
                //dirS = 252;
                confSprite(252);
            }
            break;
        case Qt::Key_Space:
            disparar=true;
            cont=1;
            if(dirS==0){
                dirS=378;
            }else if(dirS==126){
                dirS=504;
            }
            confSprite(dirS);
            break;
        default:
            QGraphicsItem::keyPressEvent(evento);
            vx=0;
        }
    }else{
        if(dirS==126 && evento->key()==Qt::Key_D){
            dirS=0;
            confSprite(dirS);
            movimiento(30,0);
            move=true;
        }else if(dirS==0 && evento->key()==Qt::Key_A){
            dirS=126;
            confSprite(dirS);
            movimiento(-30,0);
            move=true;
        }
    }
}

void Jugador::movimiento(int dx, int dy){
    x += dx;
    y += dy;
    setPos(x,y);
    //vx=0;
    //vy=0;
}

void Jugador::saltar()
{
    t+=DT;
    x+=vx*cos(30)*t;
    y+=vy*sin(30)+0.5*9.8*t*t;

    if(y<=lSup){
        vy=30;
        if(dirS==0){
            cont=1;
        }else if(dirS==126){
            cont=2;
        }
        confSprite(252);
        setPos(x,y);
    }else{
        setPos(x,y);
    }
    if(y>=lInf){
        cont=0;
        salto=false;
        t=0;
        //y=lInf;
        setPos(x,y);
        vx=0;
        cont=0;
        confSprite(dirS);
    }
}

void Jugador::caida()
{
    y += vy;
    if(y<=lInf){
        setPos(x,y);
    }else{
        caer = false;
        y=lInf;
        setPos(x,y);
        cont=0;
        confSprite(dirS);
    }

}

void Jugador::trampolin()
{
    y -= 15;
    if(y<=100){
        tram=false;
        move=true;
    }
    setPos(x,y);
}


void Jugador::confSprite(int dir){
    spriteY = dir;
    spriteX = spriteAncho*cont;
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    if(salto==false && tram==false){
        if(dirS==378 || dirS==504){
            if(cont<5){
                cont++;
            }else{
                cont=0;
            }
        }else if(dirS==635){
            if(cont<1){
                cont++;
            }else{
                cont=0;
            }
        }
        else{
            cont++;
        }
    }

    if (cont == 5){
        cont = 0;
    }

}

