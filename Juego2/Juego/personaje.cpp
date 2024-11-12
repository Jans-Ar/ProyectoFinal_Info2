#include "personaje.h"

float Personaje::getPx() const
{
    return px;
}

void Personaje::setPx(float value)
{
    px = value;
}

float Personaje::getPy() const
{
    return py;
}

void Personaje::setPy(float value)
{
    py = value;
}

Personaje::Personaje()
    : px(300), py(520),
      vx(0), vy(0),
      ax(0), ay(0),
      dx(50), dy(50)
{
    nombre = "NN";
    vida = 100;
}
Personaje::Personaje(float px, float py, string nombre)
    : px(px), py(py),
    vx(0), vy(0),
    ax(0), ay(0),
    dx(50), dy(50)
{
  this->nombre = nombre;
  vida = 100;
}

float Personaje::getVx() const
{
    return vx;
}

float Personaje::getVy() const
{
    return vy;
}

void Personaje::setVx(float newVx)
{
    vx = newVx;
}

void Personaje::setVy(float newVy)
{
    vy = newVy;
}

Proyectil* Personaje::disparar()
{
    float _vx, _vy;

    if(vx==0 && vy==0){
        _vx=30;
        _vy=0;
    }else if(vy==0){
        _vx=vx+100;
    }else if(vx==0){
        _vy=vy+10;
    }
    if(Proyectiles.size()<3){
        Proyectiles.push_back(new Proyectil(px,py,_vx,_vy));
        return Proyectiles.last();
    }

    return nullptr;
}

Proyectil* Personaje::eliminarProyectil()
{
    Proyectil *p = Proyectiles.first();
    Proyectiles.remove(0);
    return p;
}

QRectF Personaje::boundingRect() const
{
    return QRectF(0,0,dx,dy);
}

void Personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::red);
//    painter->drawEllipse(boundingRect());

    QPixmap p(":/Sprites/homero.png.png");
    painter->drawPixmap(0,0,dx,dy,p);
}

void Personaje::advance(int phase)
{
    //ax = ax;
    //ay = ay;

    vx = vx + ax*DT;
    vy = vy + ay*DT;

    px = px + vx*DT +10*ax*DT*DT;
    py = py + vy*DT +10*ay*DT*DT;

    setPos(px,py);
}










