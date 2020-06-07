#ifndef LEVEL1_H
#define LEVEL1_H

#include <QPropertyAnimation>
#include <QWidget>
#include <QRect>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <qrandom.h>
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


const int Level1EnemyNumber = 10;

class Level1 : public QWidget
{
    Q_OBJECT
public:
    explicit Level1(QWidget *parent = nullptr);

protected:

    MyPushbutton *startBtn, *backBtn;

    buildTowerBtn *bbb[Level1TowerNumber];

    update_build_button *locBtn[Level1TowerNumber];
    archeryTower *archery[Level1TowerNumber];
    magicTower *magic[Level1TowerNumber];

    int currentTime = 0;
    int timeInterval = 50;

//    basicEnemyInfo *finalEnemy[Level1EnemyNumber];

    int enemyNumber = Level1EnemyNumber;
    int currentEnemyNumber = 0;

    gnoll testmonster[10];
    orge testmonster2[5];

    QTimer *timer1;

    int Coin = 999999;
    int health = 99999;
    QLabel * status = new QLabel;

    void showEnemy();

    void initialLocBtnAndTower();

    int getMonsterType();

    void showEndScene();

    void paintEvent(QPaintEvent *);

signals:
    void level1Back();

public slots:
};

#endif // LEVEL1_H
