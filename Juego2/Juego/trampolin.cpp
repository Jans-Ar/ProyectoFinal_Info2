#include "trampolin.h"

Trampolin::Trampolin(QObject* parent)
    : QObject(parent) {}

Trampolin::Trampolin(float Px, float Py): px(Px), py(Py)
{
    setPos(px,py);
}

Trampolin::~Trampolin()
{

}

QRectF Trampolin::boundingRect() const
{
    return QRectF(0,0,60,60);
}

void Trampolin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pixman(":/trampolin.png");
    painter->drawPixmap(0,0,60,60,pixman);
}

/*QRectF Trampolin::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void Trampolin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPixmap pixman(":/trampolin.png");
    painter->drawPixmap(0,0,30,30,pixman);
}*/

float Trampolin::getPx() const
{
    return px;
}

void Trampolin::setPx(float newPx)
{
    px = newPx;
}

float Trampolin::getPy() const
{
    return py;
}

void Trampolin::setPy(float newPy)
{
    py = newPy;
}
