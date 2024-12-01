#ifndef BLOQUE_H
#define BLOQUE_H

#include <QGraphicsItem> //metodo virtual
#include <QPainter>
#include <QPixmap> //generar imagen

enum Ladrillo{ fijo=2, destructible=1, vacio=0, trampolin=3, puerta=5};
class Bloque : public QGraphicsItem
{
public:
    Bloque();
    Bloque(float px, float py, int tipo);
    ~Bloque();

    virtual QRectF boundingRect() const;//metodo virtual
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//metodo virtual

    int getTipo() const;
    float getBpx() const;
    float getBpy() const;

    void setTipo(int newTipo);
    void setBpx(float newBpx);
    void setBpy(float newBpy);
    int getDx() const;
    void setDx(int newDx);

    int getDy() const;
    void setDy(int newDy);

private:
    int tipo;
    float bpx;
    float bpy;
    int dx;
    int dy;
};

#endif // BLOQUE_H
