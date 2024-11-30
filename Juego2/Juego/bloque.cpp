#include "bloque.h"

Bloque::Bloque()
{

}

Bloque::Bloque(float px, float py, int tipo) : tipo(tipo), bpx(px), bpy(py)
{
    setPos(px,py);
}

Bloque::~Bloque()
{

}

QRectF Bloque::boundingRect() const
{

    return QRectF(0,0,30,30);
}

void Bloque::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(tipo==fijo){
        QPixmap pixman(":/piedra.png");
        painter->drawPixmap(0,0,30,30,pixman);
    }else if(tipo==destructible){
        QPixmap pixman(":/balota.png");
        painter->drawPixmap(0,0,30,30,pixman);
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
