#include "gnoll.h"
#include<qmath.h>


gnoll::gnoll()
{
    this->HP = GnollHP;
    this->speed = GnollSpeed;
    this->m_pixmap.load(GnollImage);
    this->mX = Path1X[0];
    this->mY = Path1Y[0];
    this->deathCoin = GnollDeathCoin;
    this->isFree = true;
    this->enterDamage = GnollEnterDamage;
    this->m_Rect.setWidth(m_pixmap.width());
    this->m_Rect.setHeight(m_pixmap.height());
    m_Rect.moveTo(mX, mY);
}

void gnoll::setPathStep()
{
         if(mX >= Path1X[1]) pathStep = 1;
    else if(mX >= Path1X[2]) pathStep = 2;
    else if(mX >= Path1X[3]) pathStep = 3;
    else if(mX >= Path1X[4]) pathStep = 4;
    else if(mX >= Path1X[5]) pathStep = 5;
}

void gnoll::updatePosition()
{
    if(this->isFree || (!this->isAlive) || this->enterDirection)
    {
        return;
    }


    setPathStep();

    mX -= speed/2;
    mY += speed/2;
    m_Rect.moveTo(mX, mY);
//    switch (pathStep)
//    {
//    case 1:
//    {
//        double lengthX = Path1X[1] - Path1X[0];
//        double lengthY = Path1Y[1] - Path1Y[0];
//        double length = sqrt(lengthX*2 + lengthY*2);
//        mX -= speed*(lengthX/length);
//        mY -= speed*(lengthY/length);
//        break;
//    }
//    case 2:
//    {
//        double lengthX = Path1X[2] - Path1X[1];
//        double lengthY = Path1Y[2] - Path1Y[1];
//        double length = sqrt(lengthX*2 + lengthY*2);
//        mX -= speed*(lengthX/length);
//        mY -= speed*(lengthY/length);
//        break;
//    }
//    case 3:
//    {
//        double lengthX = Path1X[3] - Path1X[2];
//        double lengthY = Path1Y[3] - Path1Y[2];
//        double length = sqrt(lengthX*2 + lengthY*2);
//        mX -= speed*(lengthX/length);
//        mY -= speed*(lengthY/length);
//        break;
//    }
//    case 4:
//    {
//        double lengthX = Path1X[4] - Path1X[3];
//        double lengthY = Path1Y[4] - Path1Y[3];
//        double length = sqrt(lengthX*2 + lengthY*2);
//        mX -= speed*(lengthX/length);
//        mY -= speed*(lengthY/length);
//        break;
//    }
//    case 5:
//    {
//        double lengthX = Path1X[5] - Path1X[4];
//        double lengthY = Path1Y[5] - Path1Y[4];
//        double length = sqrt(lengthX*2 + lengthY*2);
//        mX -= speed*(lengthX/length);
//        mY -= speed*(lengthY/length);
//        break;
//    }
//    }
}
