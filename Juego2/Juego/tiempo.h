#ifndef TIEMPO_H
#define TIEMPO_H

#include "score.h"

class Tiempo : public Score
{
public:
    Tiempo(QGraphicsItem *parent=0);
    void reducirT();
    void sigNivel();

private:
    int temp;
};

#endif // TIEMPO_H
