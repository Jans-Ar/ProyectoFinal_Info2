#ifndef PENDULOSIMPLE_H
#define PENDULOSIMPLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <cmath>
#include <QPixmap>

class PenduloSimple : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    explicit PenduloSimple(double longitud, double anguloInicial, float px, float py, QObject* parent = nullptr);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private slots:
    void actualizar();

private:
    double longitud;         // Longitud del péndulo
    double angulo;           // Ángulo actual del péndulo
    double velocidadAngular; // Velocidad angular del péndulo
    double gravedad;         // Aceleración debido a la gravedad
    const double deltaTiempo = 0.128; // Tiempo entre actualizaciones (~60 FPS)
    QPixmap pesoImagen;
    double rotacionSierra;   // Ángulo actual de rotación de la sierra
    const double velocidadRotacion = 5.0;
};

#endif // PENDULOSIMPLE_H
