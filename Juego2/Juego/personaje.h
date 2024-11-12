#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>
#include <QVector>

#include "proyectil.h"

using namespace std;

#define DT 0.2

class Personaje : public QGraphicsItem
{
private:
    int vida;
    string nombre;
    float px, py;
    float vx, vy;
    float ax, ay;
    float dx, dy;

    QVector<Proyectil *> Proyectiles;

public:
    Personaje();
    Personaje(float px, float py, string nombre);

    float getVx() const;
    float getVy() const;

    void setVx(float newVx);
    void setVy(float newVy);

    Proyectil* disparar(void);
    Proyectil* eliminarProyectil(void);

    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
            QWidget *widget = nullptr);

    void advance(int phase);
    float getPx() const;
    void setPx(float value);
    float getPy() const;
    void setPy(float value);
};

#endif // PERSONAJE_H














