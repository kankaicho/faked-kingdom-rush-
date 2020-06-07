#include "archerytower.h"

archeryTower::archeryTower(int _x, int _y)
{
    built = true;
    locX = _x;
    locY = _y;
    attackSpeed = archeryTowerAttackSpeed[0];
    attackRange = archeryTowerAttackRange[0];
    perDamage = archeryTowerPerDamage[0];
    buildCost = archeryTowerBuildCost[0];
    damageCost = archeryTowerDamageCost[0];
    judgeRect.setWidth(attackRange);
    judgeRect.setHeight(attackRange);
    judgeRect.moveTo(locX - attackRange*0.5 + towerImg.width()*0.5, locY - attackRange*0.5 + towerImg.height()*0.5);

    towerImg.load("");
}

void archeryTower::updateTower(int level)
{
    attackSpeed = archeryTowerAttackSpeed[level];
    attackRange = archeryTowerAttackRange[level];
    perDamage = archeryTowerPerDamage[level];
    buildCost = archeryTowerBuildCost[level];
    damageCost = archeryTowerDamageCost[level];

    judgeRect.setWidth(attackRange);
    judgeRect.setHeight(attackRange);
    judgeRect.moveTo(locX - attackRange*0.5 + towerImg.width()*0.5, locY - attackRange*0.5 + towerImg.height()*0.5);
}

void archeryTower::setDirLoc(int x, int y)
{
    dirX = x;
    dirY = y;
}

void archeryTower::shoot(int _dirX, int _dirY)
{
    setDirLoc(_dirX, _dirY);
    onAttackStatus = true;
    bullet.load(":/Saved Pictures/archeryTowerBullet.png");
}


void archeryTower::paintBullet(QPainter &paint)
{
    int perStepX = (dirX - locX)/10;
    int perStepY = (dirY - locY)/10;

    for(int i = 0; i < 10; i ++)
    {
        paint.drawPixmap(locX + perStepX * (i+1), locY + perStepY*(i + 1), bullet.width(), bullet.height(), bullet);
    }

}
