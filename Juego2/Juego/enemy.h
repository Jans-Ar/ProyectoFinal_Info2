#ifndef ENEMY_H
#define ENEMY_H

#include "jugador.h"

class Enemy : public Jugador
{

private:
    int dirA;

public:
    explicit Enemy(QObject *parent = nullptr);
    void confSprites(int dir);
    void moverse();
    int getDirA() const;
    void setDirA(int newDirA);
};

#endif // ENEMY_H
