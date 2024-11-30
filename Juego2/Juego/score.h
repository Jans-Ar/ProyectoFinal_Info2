#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsDropShadowEffect>
#include <QFont>

class Score: public QGraphicsTextItem{

public:
    Score(QGraphicsItem *parent=0);
    void increase();
    void decrease();
    int getscore();
    float getPx() const;
    void setPx(float newPx);

    float getPy() const;
    void setPy(float newPy);

    const QString &getTexto() const;
    void setTexto(const QString &newTexto);

    void setScore(int newScore);
    QGraphicsDropShadowEffect* createShadowEffect();

    int getTiempo() const;
    void setTiempo(int newTiempo);

protected:
    int score;
    float px;
    float py;
    int tiempo;
};

#endif // SCORE_H
