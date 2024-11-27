#include "tiempo.h"


Tiempo::Tiempo(QGraphicsItem *parent)
{
    temp = 40;

    // Configura el texto del puntaje
    setPlainText(QString("Tiempo: ") + QString::number(score)); // Inicialmente "SCORE: 0"

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
    if(temp>0){
        temp--;
        setPlainText(QString("Tiempo: ")+QString::number(temp));
    }else if(temp==0){
         setPlainText(QString("Game Over"));
    }
}
void Tiempo :: sigNivel()
{
    if (score==3 && temp>0){
         setPlainText(QString("siguiente nivel"));

        }
}
