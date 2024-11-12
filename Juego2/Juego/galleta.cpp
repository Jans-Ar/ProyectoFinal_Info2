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

float Galleta::getAx() const
{
    return ax;
}

void Galleta::setAx(float newAx)
{
    ax = newAx;
}

float Galleta::getAy() const
{
    return ay;
}

void Galleta::setAy(float newAy)
{
    ay = newAy;
}

void Galleta::advance(int phase)
{
    //vx = vx + ax*DT;
    vy = vy + ay*DT;

    //px = px + vx*DT +0.5*ax*DT*DT;
    py = py + vy*DT +0.5*ay*DT*DT;

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

Galleta::Galleta()
{
    dx = 15;
    dy = 15;
}

Galleta::Galleta(float px, float py) : px(px), py(py)
{
    dx = 16;
    dy = 16;
    setPos(px,py);
}


QRectF Galleta::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Galleta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixman(":/Sprites/donaa.png");
    painter->drawPixmap(0,0,20,20,pixman);
}

