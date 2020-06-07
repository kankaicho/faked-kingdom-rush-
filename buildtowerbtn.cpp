#include "buildtowerbtn.h"

buildTowerBtn::buildTowerBtn()
{
    QPixmap pix;
    pix.load(":/Saved Pictures/chooseTowerScene.png");
    this->setFixedSize( pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void buildTowerBtn::mousePressEvent(QMouseEvent *ev)
{

    if(ev->x() >= archeryStart_X && ev->x() <= archeryEnd_X && ev->y() >= archeryStart_Y && ev->y() <= archeryEnd_Y)
    {
        towerType = 1;
    }
    else if(ev->x() >= magicStart_X && ev->x() <= magicEnd_X && ev->y() >= magicStart_Y && ev->y() <= magicEnd_Y)
    {
        towerType = 2;
    }
    else
    {
        towerType = 0;
    }
    return QPushButton::mousePressEvent(ev);
}

void buildTowerBtn::mouseReleaseEvent(QMouseEvent *ev)
{
    return QPushButton::mouseReleaseEvent(ev);
}

void buildTowerBtn::setLoc(int _x, int _y)
{
    x = _x;
    y = _y;
}
