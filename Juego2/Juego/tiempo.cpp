#include "tiempo.h"


Tiempo::Tiempo(QGraphicsItem *parent)
{
    tiempo = 15;

    // Configura el texto del puntaje
    setPlainText(QString("Tiempo: ") + QString::number(tiempo)); // Inicialmente "SCORE: 0"

    // Cambia el color del texto a uno más vibrante
    setDefaultTextColor(Qt::white);

    // Aplica una fuente más moderna y estilizada
    setFont(QFont("Verdana", 18, QFont::Bold));

    // Añade sombra para hacerlo más llamativo
    setGraphicsEffect(createShadowEffect());

    // Ajusta la posición en la escena
    px = 800;
    py = 20;
    setPos(px, py);
}

void Tiempo::reducirT()
{
    if(tiempo>0){
        tiempo--;
        setPlainText(QString("Tiempo: ")+QString::number(tiempo));
    }
}

void Tiempo::gameOver()
{
    setFont(QFont("Verdana", 40, QFont::Bold));
    setPlainText(QString("Game Over"));
    px = 530;
    py = 380;
    setPos(px, py);
}

void Tiempo::win()
{
    setFont(QFont("Verdana", 40, QFont::Bold));
    setPlainText(QString("Siguiente Nivel"));
    px = 430;
    py = 380;
    setPos(px, py);
}


