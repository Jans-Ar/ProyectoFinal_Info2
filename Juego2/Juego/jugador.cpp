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

int Jugador::getLInf() const
{
    return lInf;
}

void Jugador::setLInf(int newLInf)
{
    lInf = newLInf;
}

int Jugador::getLSup() const
{
    return lSup;
}

void Jugador::setLSup(int newLSup)
{
    lSup = newLSup;
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

Jugador::Jugador() {
    x=0;
    y=630;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/Homero2.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    move = true;

    lInf=630;
    lSup=550;

    salto=false;
    caer=false;
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
            if(salto!=true){
                t=0;
                salto=true;
                caer=false;
                if(dirS==0){
                    cont=0;
                }else if(dirS==126){
                    cont=3;
                }
                vy=20;
                //dirS = 252;
                confSprite(252);
            }
            break;
        case Qt::Key_S:
            //movimiento(0,15);
            break;
        default:
            QGraphicsItem::keyPressEvent(evento);
            vx=0;
        }
    }
}

void Jugador::movimiento(int dx, int dy){
    x += dx;
    y += dy;
    setPos(x,y);
    vx=0;
    vy=0;
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
        y=lInf;
        setPos(x,y);
        vx=0;
        cont=0;
        confSprite(dirS);
    }
}

void Jugador::caida()
{
    y += 30;
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


void Jugador::confSprite(int dir){
    spriteY = dir;
    spriteX = spriteAncho*cont;
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    if(salto==false){
        cont++;
    }

    if (cont == 5){cont = 0;}

}
