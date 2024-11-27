#include "saludables.h"


saludables::saludables(QObject *parent)
{
    px=rand()%1300;
    py=10;
    dx=60;
    dy=60;
    if(rand()%2==0){
        pixmap = new QPixmap(":/zanahoria.png");
    }else{
        pixmap = new QPixmap(":/brocoli.PNG");
    }

    setPos(px,py);
}
