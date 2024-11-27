#ifndef GALLETA_H
#define GALLETA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <string>
#include <QPixmap>

using namespace std;

#define DT 0.2

class Galleta : public QObject, public QGraphicsItem
{
protected:
    float px, py;
    float dx, dy;
    float vx, vy;

public:   
    explicit Galleta(QObject *parent = nullptr);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QPixmap *pixmap;
    float getVx() const;
    void setVx(float newVx);
    float getVy() const;
    void setVy(float newVy);
    float getAx() const;

    void advance(float vel);
    float getPy() const;
    void setPy(float newPy);
    float getPx() const;
    void setPx(float newPx);
    float getDx() const;
    void setDx(float newDx);
    float getDy() const;
    void setDy(float newDy);
};

#endif // GALLETA_H
