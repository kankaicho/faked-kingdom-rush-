#include "orge.h"

orge::orge()
{
    this->HP = OrgeHP;
    this->speed = OrgeSpeed;
    this->m_pixmap.load(OrgeImage);
    this->mX = Path2X[0];
    this->mY = Path2Y[0];
    this->deathCoin = OrgeDeathCoin;
    this->isFree = true;
    this->enterDamage = OrgeEnterDamage;
    this->m_Rect.setWidth(m_pixmap.width());
    this->m_Rect.setHeight(m_pixmap.height());
    m_Rect.moveTo(mX, mY);
}

void orge::setPathStep()
{
         if(mX >= Path2X[1]) pathStep = 1;
    else if(mX >= Path2X[2]) pathStep = 2;
    else if(mX >= Path2X[3]) pathStep = 3;
    else if(mX >= Path2X[4]) pathStep = 4;
}

void orge::updatePosition()
{
    if(this->isFree || (!this->isAlive) || this->enterDirection)
    {
        return;
    }

    m_Rect.moveTo(mX, mY);

    setPathStep();

    switch (pathStep)
    {
    case 1:
        mX -= speed;
        break;
    case 2:
        mX -=speed;
        break;
    case 3:
        mX -= speed;
        break;
    case 4:
        mX -= speed;
        break;
    }
}
