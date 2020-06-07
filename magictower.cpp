#include "magictower.h"

magicTower::magicTower(int _x, int _y)
{
    built = true;
    locX = _x;
    locY = _y;
    attackSpeed = magicTowerAttackSpeed[0];
    attackRange = magicTowerAttackRange[0];
    perDamage = magicTowerPerdamage[0];
    buildCost = magicTowerBuildCost[0];
    damageCost = magicTowerDamageCost[0];
    judgeRect.setWidth(attackRange);
    judgeRect.setHeight(attackRange);
    judgeRect.moveTo(locX,locY);

    towerImg.load("");
}

void magicTower::updateTower(int level)
{
    attackSpeed = magicTowerAttackSpeed[level];
    attackRange = magicTowerAttackRange[level];
    perDamage = magicTowerPerdamage[level];
    buildCost = magicTowerBuildCost[level];
    damageCost = magicTowerDamageCost[level];

    judgeRect.setWidth(attackRange);
    judgeRect.setHeight(attackRange);
    judgeRect.moveTo(locX - attackRange*0.5 + towerImg.width()*0.5, locY - attackRange*0.5 + towerImg.height()*0.5);
}

void magicTower::setDirLoc(int x, int y)
{
    dirX = x;
    dirY = y;
}

void magicTower::shoot(int _dirX, int _dirY)
{
    setDirLoc(_dirX, _dirY);
    onAttackStatus = true;
    bullet.load(":/Saved Pictures/magicTowerBullet.png");
}


void magicTower::paintBullet(QPainter &paint)
{
    int perStepX = (dirX - locX)/8;
    int perStepY = (dirY - locY)/8;
    for(int i = 0; i < 8; i ++)
    {
        paint.drawPixmap(locX + perStepX * (i+1), locY + perStepY*(i + 1), bullet.width(), bullet.height(), bullet);
    }
}
