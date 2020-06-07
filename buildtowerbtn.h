#ifndef BUILDTOWERBTN_H
#define BUILDTOWERBTN_H

#include <QPushButton>
#include <QPropertyAnimation>
#include<QMouseEvent>
#include "basicinfo.h"
#include<QDebug>

const int ARCHERY = 1;
const int  MAGIC  = 2;

class buildTowerBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit buildTowerBtn();

    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);

    void showChooseWidget();

    void update();

    void setLoc(int _x ,int _y);

    int getTowerType() { return towerType; }
protected:
    int x, y;
    int towerType = 0;

signals:

public slots:
};

#endif // BUILDTOWERBTN_H
