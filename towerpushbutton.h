#ifndef TOWERPUSHBUTTON_H
#define TOWERPUSHBUTTON_H

#include <QPushButton>
#include <QPainter>
#include "archerytower.h"

class towerPushButton : public QPushButton
{
    Q_OBJECT
public:

    explicit towerPushButton(int _x, int _y);

    explicit towerPushButton();

    archeryTower *tow = new towerPushButton;
protected:


signals:

public slots:
};

#endif // TOWERPUSHBUTTON_H
