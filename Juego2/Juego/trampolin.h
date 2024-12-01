#ifndef TRAMPOLIN_H
#define TRAMPOLIN_H

#include <QGraphicsItem> //metodo virtual
#include <QPainter>
#include <QPixmap> //generar imagen

class Trampolin : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Trampolin(QObject* parent = nullptr);
    Trampolin(float Px, float Py);
    ~Trampolin();

    QRectF boundingRect() const override; // Método virtual obligatorio
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override; // Método virtual obligatorio

    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

private:
    float px;
    float py;
};

#endif // TRAMPOLIN_H
