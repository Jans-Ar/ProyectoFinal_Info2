#ifndef JUGADOR_H
#define JUGADOR_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsView>
#include <QTimer>
#define DT 0.2

class Jugador:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    qreal x = 0;
    qreal y = 0;
    int spriteX = 0;
    int spriteY = 0;
    int spriteAncho = 129;
    int spriteAlto = 126;
    QPixmap hojaSprites; //plantilla de spirtes
    QPixmap sprite;      //sprite actual
    int cont = 0;
    QTimer *timerMov;
    float vx, vy;
    float ax, ay;
    float t;

    bool salto=false;
public:
    Jugador();
    void keyPressEvent(QKeyEvent *evento) override;
    void movimiento(int vx2, int vy2);
    void saltar();
    void confSprite(int dir);
    float getVx() const;
    void setVx(float newVx);
    float getVy() const;
    void setVy(float newVy);
    float getAx() const;
    void setAx(float newAx);
    float getAy() const;
    void setAy(float newAy);
    bool getSalto() const;
    void setSalto(bool newSalto);
    qreal getY() const;
    void setY(qreal newY);
    qreal getX() const;
    void setX(qreal newX);
    float getT() const;
    void setT(float newT);
};

#endif // JUGADOR_H
