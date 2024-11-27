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

Jugador::Jugador() {
    x=0;
    y=630;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/Homero.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
}

void Jugador::keyPressEvent(QKeyEvent * evento){
    switch(evento->key()){
    case Qt::Key_A:
        if(salto!=true){
            movimiento(-15,0);
            confSprite(126);
            vx=-25;
        }
        break;
    case Qt::Key_D:
        if(salto!=true){
            movimiento(15,0);
            confSprite(0);
            vx=25;
        }
        break;
    case Qt::Key_W:
        //movimiento(vx,-15);
        if(salto!=true){
            t=0;
            salto=true;
            vy=20;
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

void Jugador::movimiento(int dx, int dy){
    x += dx;
    y += dy;
    setPos(x,y);
    vx=0;
    vy=0;
}

void Jugador::saltar()
{
    /*x += vx;
    y += vy;*/
    t+=DT;
    x+=vx*cos(30)*t;
    y+=vy*sin(30)+0.5*9.8*t*t;

    if(y<550){
        vy=30;
    }
    if(y>=630){
        salto=false;
        t=0;
        y=630;
        setPos(x,y);
        vx=0;
    }else{
        setPos(x,y);
    }
}


void Jugador::confSprite(int dir){
    spriteY = dir;
    spriteX = spriteAncho*cont;
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    cont++;
    if (cont == 5){cont = 0;}

}
