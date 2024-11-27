#ifndef SALUDABLES_H
#define SALUDABLES_H

#include <QObject>
#include <QGraphicsItem>
#include "galleta.h"

class saludables : public Galleta
{
    Q_OBJECT
public:
    explicit saludables(QObject *parent = nullptr);
};

#endif // SALUDABLES_H
