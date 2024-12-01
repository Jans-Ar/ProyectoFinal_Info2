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
    //x=600;
    //y=200;
    spriteX = 0;
    spriteY = 0;
    spriteAncho = 125;
    spriteAlto = 127;
    setFlag(QGraphicsItem::ItemIsFocusable);
    hojaSprites.load(":/enemy2.png");
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    move = true;

    lInf=630;
    lSup=550;

    salto=false;
    caer=false;
    setPos(x,y);
}

void Enemy::confSprites(int dir)
{
    spriteY = dir;
    spriteX = spriteAncho*cont;
    sprite = hojaSprites.copy(spriteX,spriteY,spriteAncho,spriteAlto);
    setPixmap(sprite); //imagen que se mostrara
    if(salto==false){
        cont++;
    }

    if (cont == 4){cont = 0;}
}

void Enemy::moverse()
{
    if(move==true){
        if(dirS==400 && x<=700){
            cont=0;
            dirS=265;
            vx=10;
        }else if(dirS==265 && x>=1100){
            cont=0;
            dirS=400;
            vx=-10;
        }
        confSprites(dirS);
        x += vx;
        setPos(x,y);
    }

}

