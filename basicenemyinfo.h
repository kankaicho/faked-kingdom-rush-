#ifndef BASICENEMYINFO_H
#define BASICENEMYINFO_H

#include<QPixmap>
#include <QTimer>
#include <QWidget>
#include "basicinfo.h"

class basicEnemyInfo
{
public:
    basicEnemyInfo();
    QPixmap m_pixmap;
    QRect m_Rect;
    double mX, mY;
    int speed;
    int HP;
    int deathCoin;
    int phsicalResistance;
    int magicResistance;
    int enterDamage;
    bool causeDamage = false;
    bool isFree = true;
    bool isAlive = true;
    bool enterDirection = false;

    virtual void updatePosition() = 0;
    virtual void setPathStep() = 0;

};

#endif // BASICENEMYINFO_H
