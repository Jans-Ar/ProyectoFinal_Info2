#include "pendulosimple.h"

PenduloSimple::PenduloSimple(double longitud, double anguloInicial, float px, float py, QObject *parent)
    : QObject(parent), longitud(longitud), angulo(anguloInicial), velocidadAngular(0), gravedad(9.8) {
    // Configurar el temporizador para actualizar el movimiento

    pesoImagen = QPixmap(":/sierra.png");
    rotacionSierra = 0;
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PenduloSimple::actualizar);
    timer->start(16); // Aproximadamente 60 FPS
    setPos(px,py);
}

QRectF PenduloSimple::boundingRect() const {
    // Rectángulo de los límites para propósitos de renderizado
    //return QRectF(-longitud - 10, -longitud - 10, longitud * 2 + 20, longitud * 2 + 20);
    return QRectF(-longitud - 50, -longitud - 50, longitud * 2 + 100, longitud * 2 + 100);
}

QPainterPath PenduloSimple::shape() const
{
    QPainterPath path;

    // Posición actual del peso
    double x = longitud * std::sin(angulo);
    double y = longitud * std::cos(angulo);

    // Parte 1: La barra del péndulo
    path.moveTo(0, 0); // Punto de suspensión
    path.lineTo(x, y); // Línea hacia el peso

    // Parte 2: El peso del péndulo (círculo)
    path.addEllipse(x - 20, y - 20, 40, 40); // Círculo con diámetro de 40

    return path;
}

void PenduloSimple::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option)
    Q_UNUSED(widget)

    // Dibujar el péndulo
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);

    // Punto de suspensión
    painter->drawEllipse(QPointF(0, 0), 5, 5);

    // Posición del peso
    double x = longitud * std::sin(angulo);
    double y = longitud * std::cos(angulo);

    // Dibujar la cuerda
    painter->drawLine(QPointF(0, 0), QPointF(x, y));

    //painter->setPen(Qt::DashLine);
    //painter->setBrush(Qt::NoBrush);
    //painter->drawPath(shape()); // Dibuja el área de colisión

    // Dibujar el peso
    //painter->setBrush(Qt::black);
    //painter->drawEllipse(QPointF(x, y), 10, 10);


    if (!pesoImagen.isNull()) {
        QPointF posicionPeso(x, y);
        painter->save(); // Guardar el estado del pintor

        // Trasladar el origen al centro del peso y rotar
        painter->translate(posicionPeso);
        painter->rotate(rotacionSierra); // Aplicar la rotación
        painter->translate(-pesoImagen.width() / 2, -pesoImagen.height() / 2);

        // Dibujar la imagen rotada
        painter->drawPixmap(0, 0, pesoImagen);

        painter->restore(); // Restaurar el estado del pintor
    }

}

void PenduloSimple::actualizar() {

    prepareGeometryChange(); // Notificar a Qt que la geometría está cambiando

    // Ecuaciones del movimiento del péndulo
    double aceleracionAngular = -(gravedad / longitud) * std::sin(angulo);
    velocidadAngular += aceleracionAngular * deltaTiempo;
    angulo += velocidadAngular * deltaTiempo;

    // Incrementar el ángulo de rotación de la sierra
    rotacionSierra += velocidadRotacion;
    if (rotacionSierra >= 360.0) rotacionSierra -= 360.0;

    // Redibujar el péndulo
    update();
}
