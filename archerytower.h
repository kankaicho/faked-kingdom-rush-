#ifndef ARCHERYTOWER_H
#define ARCHERYTOWER_H

#include "basictowerinfo.h"

class archeryTower : public basicTowerInfo
{
public:
    archeryTower(int _x, int _y);
    archeryTower();

    int temInterval = 0;

    int dirX, dirY;

    virtual void updateTower(int level);

    void setDirLoc(int x, int y);

    void shoot(int x, int y);

    void paintBullet(QPainter &paint);

};

#endif // ARCHERYTOWER_H
