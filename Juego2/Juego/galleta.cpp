#include "galleta.h"

float Galleta::getVx() const
{
    return vx;
}

void Galleta::setVx(float newVx)
{
    vx = newVx;
}

float Galleta::getVy() const
{
    return vy;
}

void Galleta::setVy(float newVy)
{
    vy = newVy;
}

void Galleta::advance(float vel)
{
    py += vel;
    setPos(px,py);

}

float Galleta::getPy() const
{
    return py;
}

void Galleta::setPy(float newPy)
{
    py = newPy;
}

float Galleta::getPx() const
{
    return px;
}

void Galleta::setPx(float newPx)
{
    px = newPx;
}

float Galleta::getDx() const
{
    return dx;
}

void Galleta::setDx(float newDx)
{
    dx = newDx;
}

float Galleta::getDy() const
{
    return dy;
}

void Galleta::setDy(float newDy)
{
    dy = newDy;
}


Galleta::Galleta(QObject *parent)
: QObject{parent}
{
    px=rand()%1300;
    py=10;
    dx = 60;
    dy = 60;
    if(rand()%2==0){
        pixmap = new QPixmap(":/galleta.png");
    }else{
        pixmap = new QPixmap(":/dona.png");
    }
    setPos(px,py);
}


QRectF Galleta::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Galleta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0,dx,dy,*pixmap);
}
