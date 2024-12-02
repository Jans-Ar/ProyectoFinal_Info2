#include "enemy.h"

int Enemy::getDirA() const
{
    return dirA;
}

void Enemy::setDirA(int newDirA)
{
    dirA = newDirA;
}

Enemy::Enemy(QObject *parent)
{
    spriteX = 0;
    spriteY = 0;
    spriteAncho = 85;  // Ancho de cada sprite
    spriteAlto = 139;  // Alto de cada sprite
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/MargeEnemy.png");
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite); // Imagen inicial que se mostrará
    move = true;

    lInf = 630;  // Límite inferior
    lSup = 550;  // Límite superior

    salto = false;
    caer = false;
    x = 600;  // Posición inicial X
    y = 200;  // Posición inicial Y
    dirS = 400; // Dirección inicial (derecha)
    vx = 10;    // Velocidad inicial
    setPos(x, y);
}

void Enemy::confSprites(int dir)
{
    // Cambiar spriteY según la dirección (primera fila = derecha, segunda fila = izquierda)
    if (dir == 400) { // Dirección hacia la derecha
        spriteY = 0; // Primera fila
    } else if (dir == 265) { // Dirección hacia la izquierda
        spriteY = 139; // Segunda fila
    }

    // Actualizar spriteX para avanzar en la animación
    spriteX = spriteAncho * cont;
    sprite = hojaSprites.copy(spriteX, spriteY, spriteAncho, spriteAlto);
    setPixmap(sprite); // Imagen que se mostrará

    // Control del contador para recorrer los cuadros de animación
    if (!salto) {
        cont++;
    }

    if (cont == 4) { // Volver al primer cuadro si se llegó al final de la animación
        cont = 0;
    }
}

void Enemy::moverse()
{
    if (move) {
        // Cambiar dirección al alcanzar los límites
        if (dirS == 400 && x >= 1100) { // Cambiar a dirección izquierda
            cont = 0;
            dirS = 265; // Actualizar dirección
            vx = -10;   // Velocidad hacia la izquierda
        } else if (dirS == 265 && x <= 700) { // Cambiar a dirección derecha
            cont = 0;
            dirS = 400; // Actualizar dirección
            vx = 10;    // Velocidad hacia la derecha
        }

        // Actualizar los sprites y la posición
        confSprites(dirS);
        x += vx; // Actualizar la posición X del enemigo
        setPos(x, y);
    }
}