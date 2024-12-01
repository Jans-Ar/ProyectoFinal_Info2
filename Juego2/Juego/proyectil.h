#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>
#include <QTimer>
#include <QDebug>

using namespace std;

class Proyectil :public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    float px, py;
    float vx, vy;
    float dx, dy;
    char Dir;

    //QTimer *duracion;

public:
    Proyectil();
    Proyectil(float px, float py, char dir);
    ~Proyectil();

    float getPx() const;
    float getPy() const;
    float getVx() const;
    float getVy() const;

    void setPx(float value);
    void setPy(float value);
    void setVx(float newVx);
    void setVy(float newVy);

    virtual QRectF boundingRect() const;
    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);

    void trayectoria();


    char getDir() const;
    void setDir(char newDir);

public slots:
    void onDestruir(void);

signals:
    void finProyectil(void);
};

#endif // PROYECTIL_H
