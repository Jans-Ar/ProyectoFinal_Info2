#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    // Configura el texto del puntaje
    setPlainText(QString("SCORE: ") + QString::number(score)); // Inicialmente "SCORE: 0"

    // Cambia el color del texto a uno más vibrante
    setDefaultTextColor(Qt::white);

    // Aplica una fuente más moderna y estilizada
    setFont(QFont("Verdana", 18, QFont::Bold));

    // Añade sombra para hacerlo más llamativo
    setGraphicsEffect(createShadowEffect());

    // Ajusta la posición en la escena
    px = 615;
    py = 20;
    setPos(px, py);
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

void Score::decrease()
{
    score=0;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getscore(){
    return score;
}

float Score::getPx() const
{
    return px;
}

void Score::setPx(float newPx)
{
    px = newPx;
}

float Score::getPy() const
{
    return py;
}

void Score::setPy(float newPy)
{
    py = newPy;
}

void Score::setScore(int newScore)
{
    score = newScore;
}

QGraphicsDropShadowEffect *Score::createShadowEffect()
{
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setOffset(2, 2); // Desplazamiento de la sombra
    shadowEffect->setBlurRadius(10); // Suavizado
    shadowEffect->setColor(QColor(0, 0, 0, 160)); // Sombra semitransparente negra
    return shadowEffect;
}


