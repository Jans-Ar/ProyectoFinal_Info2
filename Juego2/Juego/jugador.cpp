#include "jugador.h"
#include <QKeyEvent>
#include <QTimer>
#include <QDebug>
#include <QString>

float Jugador::getVx() const
{
    return vx;
}

void Jugador::setVx(float newVx)
{
    vx = newVx;
}

float Jugador::getVy() const
{
    return vy;
}

void Jugador::setVy(float newVy)
{
    vy = newVy;
}

float Jugador::getAx() const
{
    return ax;
}

void Jugador::setAx(float newAx)
{
    ax = newAx;
}

float Jugador::getAy() const
{
    return ay;
}

void Jugador::setAy(float newAy)
{
    ay = newAy;
}

bool Jugador::getSalto() const
{
    return salto;
}

void Jugador::setSalto(bool newSalto)
{
    salto = newSalto;
}

qreal Jugador::getY() const
{
    return y;
}

void Jugador::setY(qreal newY)
{
    y = newY;
}

qreal Jugador::getX() const
{
    return x;
}

void Jugador::setX(qreal newX)
{
    x = newX;
}

float Jugador::getT() const
{
    return t;
}

void Jugador::setT(float newT)
{
    t = newT;
}

bool Jugador::getMove() const
{
    return move;
}

void Jugador::setMove(bool newMove)
{
    move = newMove;
}

int Jugador::getLInf() const
{
    return lInf;
}

void Jugador::setLInf(int newLInf)
{
    lInf = newLInf;
}

int Jugador::getLSup() const
{
    return lSup;
}

void Jugador::setLSup(int newLSup)
{
    lSup = newLSup;
}

bool Jugador::getCaer() const
{
    return caer;
}

void Jugador::setCaer(bool newCaer)
{
    caer = newCaer;
}

int Jugador::getCont() const
{
    return cont;
}

void Jugador::setCont(int newCont)
{
    cont = newCont;
}

int Jugador::getDirS() const
{
    return dirS;
}

void Jugador::setDirS(int newDirS)
{
    dirS = newDirS;
}

// Constructor
Jugador::Jugador() {
    x = 0;
    y = 630;
    spriteX = 0;
    spriteY = 0;
    spriteAncho = 129;
    spriteAlto = 126;
    velocidad = 8;
    salto = false;
    caer = false;

    hojaSprites.load(":/Homero2.png");
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite); // Imagen que se mostrará

    setFlag(QGraphicsItem::ItemIsFocusable, true);

    lInf = 630;
    lSup = 550;

    // Inicializar y conectar el temporizador para actualización
    timerMov = new QTimer(this);
    connect(timerMov, &QTimer::timeout, this, &Jugador::update);
    timerMov->start(16); // ~60 FPS
}

// Manejo de eventos de teclado
void Jugador::keyPressEvent(QKeyEvent *evento) {
    switch (evento->key()) {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        keys[evento->key()] = true;
        break;
    default:
        QGraphicsItem::keyPressEvent(evento);
        break;
    }
}

void Jugador::keyReleaseEvent(QKeyEvent *evento) {
    switch (evento->key()) {
    case Qt::Key_W:
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        keys[evento->key()] = false;
        break;
    default:
        QGraphicsItem::keyReleaseEvent(evento);
        break;
    }
}

// Lógica de actualización del movimiento
void Jugador::update() {
    int speed_x = 0;

    if (keys[Qt::Key_A] && x > -30) {
        speed_x -= velocidad;
        if (!salto) {
            dirS = 126;
            confSprite(dirS);
        }
    }

    if (keys[Qt::Key_D] && x < 1250) {
        speed_x += velocidad;
        if (!salto) {
            dirS = 0;
            confSprite(dirS);
        }
    }

    if (keys[Qt::Key_W]) {
        if (!salto) {
            t = 0;
            salto = true;
            caer = false;
            vy = 12; // Reducida para un salto más bajo
            confSprite(252); // Cambiar sprite al de salto
        }
    }

    x += speed_x;
    setPos(x, y);

    if (salto) {
        saltar(); // Actualiza la lógica del salto
    }
}
// Lógica de salto
void Jugador::saltar() {
    t += DT;

    // Reducir la fuerza de salto para hacerlo más lento
    float saltoFuerza = 12.0f;  // Redujimos este valor para un salto más lento
    vy = saltoFuerza;           // Aplica la fuerza de salto al valor de vy

    // Si estamos subiendo (y está decreciendo)
    if (vy > 0) {
        // Reduce la velocidad de subida, hace que el salto sea más lento
        y -= vy * t - 0.5 * 5 * t * t;  // Movimiento ascendente más lento
    }
    // Si estamos cayendo (y está incrementando)
    else {
        // Reducir aún más la aceleración de la caída para que sea más lenta
        y += vy * t + 0.5 * 0.5 * t * t;  // Movimiento descendente más lento y fluido
    }

    if (y <= lSup) {
        // Fase de subida: Cambiar el sprite solo en subida
        if (vy > 0) {
            if (dirS == 0) {
                cont = 1;
            } else if (dirS == 126) {
                cont = 2;
            }
            confSprite(252); // Cambiar sprite al de salto
        }
        setPos(x, y);
    } else if (y >= lInf) {
        // Fase de descenso: Cambiar sprite de caída
        if (vy < 0) {
            cont = 3; // Sprite de caída
            confSprite(378); // Cambiar sprite para la caída
        }

        salto = false;
        t = 0;
        y = lInf;
        setPos(x, y);
        vx = 0;
        cont = 0;
        confSprite(dirS);
    } else {
        setPos(x, y);
    }
}



void Jugador::caida()
{
    y += 30; // Incremento en la posición vertical
    if (y <= lInf) {
        setPos(x, y); // Actualiza la posición si no supera el límite inferior
    } else {
        caer = false; // Detiene la caída
        y = lInf;     // Ajusta la posición a la línea límite inferior
        setPos(x, y);
        cont = 0;     // Reinicia el contador de sprites
        confSprite(dirS); // Configura el sprite con la dirección actual
    }
}

// Configuración del sprite
void Jugador::confSprite(int dir) {
    spriteY = dir;
    spriteX = spriteAncho * cont;
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite); // Imagen que se mostrará

    // Solo incrementa el contador después de un intervalo y solo para un tipo de fase
    if (++spriteCont >= 5) {  // Este es el intervalo para cambiar de sprite
        cont++;
        spriteCont = 0; // Reinicia el contador para el siguiente intervalo
    }

    // Reinicia el contador si llega al límite de sprites (5 en este caso)
    if (cont == 5) {
        cont = 0;
    }
}
