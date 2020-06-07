#ifndef LEVEL2_H
#define LEVEL2_H

#include <QPropertyAnimation>
#include <QWidget>
#include <QRect>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QMap>
#include "gnoll.h"
#include "orge.h"
#include "archerytower.h"
#include "magictower.h"
#include "mypushbutton.h"
#include "update_build_button.h"
#include "basicinfo.h"

#include <QFont>
#include <QLabel>

class Level2 : public QWidget
{
    Q_OBJECT
public:
    explicit Level2(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);


protected:


    buildTowerBtn *bbb[Level2TowerNumber];
    update_build_button *locBtn[Level2TowerNumber];
    archeryTower *archery[Level2TowerNumber];
    magicTower *magic[Level2TowerNumber];

    int currentTime = 0;
    int timeInterval = 50;
    gnoll testmonster[10];
    orge testmonster2[5];

    QTimer *timer1;

    int enemyNumber = 10;

    int Coin = 999999;
    int health = 99999;
    QLabel * status = new QLabel;

    void showEnemy();
    void showEndScene();

    void initialLocBtnAndTower();

signals:
    void level1Back();

public slots:
};

#endif // LEVEL2_H
