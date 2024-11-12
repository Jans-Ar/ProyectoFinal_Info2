#include "proyectil.h"

float Proyectil::getPx() const
{
    return px;
}

void Proyectil::setPx(float value)
{
    px = value;
}

float Proyectil::getPy() const
{
    return py;
}

void Proyectil::setPy(float value)
{
    py = value;
}

float Proyectil::getVx() const
{
    return vx;
}

void Proyectil::setVx(float value)
{
    vx = value;
}

float Proyectil::getVy() const
{
    return vy;
}

void Proyectil::setVy(float value)
{
    vy = value;
}

Proyectil::Proyectil()
{
    dx = 15;
    dy = 15;
}

Proyectil::Proyectil(float px, float py,float vx, float vy)
    : px(px), py(py), vx(vx), vy(vy)
{
    dx = 16;
    dy = 16;
    setPos(px+8,py+8);

    duracion = new QTimer();
    duracion->start(2000);

    connect(duracion, &QTimer::timeout, this, &Proyectil::onDestruir);
}

Proyectil::~Proyectil()
{
    delete duracion;
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}

void Proyectil::advance(int phase)
{
    px = px + vx*DT;
    py = py + vy*DT;
    setPos(px,py);
}

void Proyectil::onDestruir()
{
    qDebug()<<"Fin proyectil";
    duracion->stop();
    emit finProyectil();
}
