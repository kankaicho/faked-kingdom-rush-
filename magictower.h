#ifndef MAGICTOWER_H
#define MAGICTOWER_H

#include "basictowerinfo.h"

class magicTower : public basicTowerInfo
{
public:
    magicTower(int _x, int _y);

    magicTower();

    int temInterval = 0;

    int dirX, dirY;

    virtual void updateTower(int level);

    void setDirLoc(int x, int y);

    void shoot(int x, int y);

    void paintBullet(QPainter &paint);
};

#endif // MAGICTOWER_H
