#ifndef ORGE_H
#define ORGE_H

#include "basicenemyinfo.h"

class orge : public basicEnemyInfo
{
public:
    int pathStep = 0;
    orge();
    virtual void updatePosition();
    virtual void setPathStep();
};

#endif // ORGE_H
