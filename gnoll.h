#ifndef GNOLL_H
#define GNOLL_H

#include "basicenemyinfo.h"

class gnoll : public basicEnemyInfo
{
public:
    int pathStep = 0;
    gnoll();
    virtual void updatePosition();
    virtual void setPathStep();
};

#endif // GNOLL_H
