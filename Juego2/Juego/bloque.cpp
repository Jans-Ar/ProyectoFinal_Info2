#include "bloque.h"

Bloque::Bloque()
{

}

Bloque::Bloque(float px, float py, int tipo) : tipo(tipo), bpx(px), bpy(py)
{
    setPos(px,py);
    if(tipo==puerta){
        dx=138;
        dy=124;
    }else{
        dx=30;
        dy=30;
    }
}

Bloque::~Bloque()
{

}

QRectF Bloque::boundingRect() const
{

    return QRectF(0,0,dx,dy);
}

void Bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(tipo==fijo){
        QPixmap pixman(":/piedra.png");
        painter->drawPixmap(0,0,30,30,pixman);
    }else if(tipo==destructible){
        QPixmap pixman(":/balota.png");
        painter->drawPixmap(0,0,30,30,pixman);
    }else if(tipo==trampolin){
        QPixmap pixman(":/trampolin.png");
        painter->drawPixmap(0,0,30,30,pixman);
    }else if(tipo==puerta){
        QPixmap pixman(":/planta.png");
        painter->drawPixmap(0,0,dx,dy,pixman);
    }
}

int Bloque::getTipo() const
{
    return tipo;
}

void Bloque::setTipo(int newTipo)
{
    tipo = newTipo;
}

float Bloque::getBpx() const
{
    return bpx;
}

void Bloque::setBpx(float newBpx)
{
    bpx = newBpx;
}

float Bloque::getBpy() const
{
    return bpy;
}

void Bloque::setBpy(float newBpy)
{
    bpy = newBpy;
}

int Bloque::getDx() const
{
    return dx;
}

void Bloque::setDx(int newDx)
{
    dx = newDx;
}

int Bloque::getDy() const
{
    return dy;
}

void Bloque::setDy(int newDy)
{
    dy = newDy;
}
