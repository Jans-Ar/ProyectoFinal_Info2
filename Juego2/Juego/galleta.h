#ifndef GALLETA_H
#define GALLETA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <string>
#include <QPixmap>

using namespace std;

#define DT 0.2

class Galleta : public QGraphicsItem
{
private:
    float px, py;
    float dx, dy;
    float vx, vy;
    float ax, ay;

public:    
    Galleta();
    Galleta(float px, float py);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    float getVx() const;
    void setVx(float newVx);
    float getVy() const;
    void setVy(float newVy);
    float getAx() const;
    void setAx(float newAx);
    float getAy() const;
    void setAy(float newAy);

    void advance(int phase);
    float getPy() const;
    void setPy(float newPy);
    float getPx() const;
    void setPx(float newPx);
};

#endif // GALLETA_H
