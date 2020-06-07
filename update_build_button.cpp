#include "update_build_button.h"

update_build_button::update_build_button()
{
    this->normalImgPath = ":/Saved Pictures/Loc.png";
    QPixmap pix;
    pix.load(normalImgPath);
    this->setFixedSize( pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

void update_build_button::mousePressEvent(QMouseEvent *ev)
{
    pix.load(normalImgPath);
    this->setFixedSize( pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    if(ev->button() == Qt::LeftButton)
    {

        if(levelStatus == 0 || levelStatus > 3)
        {
            return QPushButton::mousePressEvent(ev);
        }

        if(towerChoice == 1)
        {
            ar->updateTower(levelStatus);
            QString str = QString(":/Saved Pictures/archeryTowerLevel%1.png").arg(levelStatus);
            changeStatusInto(str);
        }

        else if(towerChoice == 2)
        {
            ma->updateTower(levelStatus);
            QString str = QString(":/Saved Pictures/magicTowerLevel%1").arg(levelStatus);
            changeStatusInto(str);
        }
        levelStatus ++;

        return QPushButton::mousePressEvent(ev);
    }

    else if(ev->button() == Qt::RightButton)
    {
        levelStatus = 0;

        if(towerChoice == 1)
        {
            backCoin = ar->damageCost;
            ar->updateTower(levelStatus);
        }

        else if(towerChoice == 2)
        {
            backCoin = ma->damageCost;
            ma->updateTower(levelStatus);
        }

        towerChoice = 0;

        normalImgPath = ":/Saved Pictures/Loc.png";
        return QPushButton::mousePressEvent(ev);
    }

    return QPushButton::mousePressEvent(ev);
}

void update_build_button::mouseReleaseEvent(QMouseEvent *ev)
{
    pix.load(normalImgPath);
    this->setFixedSize( pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
    return QPushButton::mouseReleaseEvent(ev);
}

void update_build_button::changeStatusInto(QString changeImg)
{
    normalImgPath = changeImg;
}

void update_build_button::getTowerArchery(archeryTower *_ar, int _towerChoice)
{
    towerChoice = _towerChoice;
    ar = _ar;
    levelStatus = 1;
    ar->updateTower(levelStatus);
    QString str = QString(":/Saved Pictures/archeryTowerLevel%1.png").arg(levelStatus);
    changeStatusInto(str);

}

void update_build_button::getTowerMagic(magicTower *_ma, int _towerChoice)
{
    towerChoice = _towerChoice;
    ma =_ma;
    levelStatus = 1;
    ma->updateTower(levelStatus);
    QString str = QString(":/Saved Pictures/magicTowerLevel%1").arg(levelStatus);
    changeStatusInto(str);

}

void update_build_button::setLoc(int _x, int _y)
{
    x = _x;
    y = _y;
}


int update_build_button::getBackCoin()
{
    int temCoin = backCoin;
    backCoin = 0;
    return temCoin;
}

