#ifndef BASICTOWERINFO_H
#define BASICTOWERINFO_H

#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include "basicinfo.h"
#include <QPropertyAnimation>

class basicTowerInfo
{
public:
    basicTowerInfo();

    bool onAttackStatus = false;

    int getX() { return locY; }
    int getY() { return locX; }
    void updateTower(int level);

    int attackRange;
    int attackSpeed;
    int perDamage;
    int buildCost;
    int damageCost;
    int locX, locY;
    bool built = false;

    QPixmap towerImg;
        QPixmap bullet;
    QRect judgeRect;
};

#endif // BASICTOWERINFO_H
