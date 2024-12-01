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

char Proyectil::getDir() const
{
    return Dir;
}

void Proyectil::setDir(char newDir)
{
    Dir = newDir;
}

Proyectil::Proyectil()
{
    dx = 15;
    dy = 15;
}

Proyectil::Proyectil(float px, float py, char dir)
    : px(px), py(py)
{
    Dir = dir;
    vx=30;
    vy=10;
    dx = 24;
    dy = 24;
    setPos(px,py);

    //duracion = new QTimer();
    //duracion->start(2000);

    //connect(duracion, &QTimer::timeout, this, &Proyectil::onDestruir);
}

Proyectil::~Proyectil()
{
    //delete duracion;
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(Dir=='D'){
        QPixmap pixman(":/balaD.png");
        painter->drawPixmap(0,0,dx,dy,pixman);
    }else if(Dir=='I'){
        QPixmap pixman(":/balaI.png");
        painter->drawPixmap(0,0,dx,dy,pixman);
    }

}

void Proyectil::trayectoria()
{
    if(Dir=='D'){
        px = px + vx;
    }else if(Dir=='I'){
        px = px - vx;
    }

    //py = py + vy*DT;
    setPos(px,py);
}

void Proyectil::onDestruir()
{
    qDebug()<<"Fin proyectil";
    //duracion->stop();
    emit finProyectil();
}
