#ifndef UPDATE_BUILD_BUTTON_H
#define UPDATE_BUILD_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include<QMouseEvent>
#include<QDebug>
#include "buildtowerbtn.h"
#include "archerytower.h"
#include "magictower.h"
#include "basicinfo.h"

class update_build_button : public QPushButton
{
    Q_OBJECT
public:
    explicit update_build_button();
    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);

    void changeStatusInto(QString changeImg);

    void getTowerArchery(archeryTower *_ar, int _towerChoice);
    void getTowerMagic(magicTower *_ma, int _towerChoice);
    void setLoc(int _x, int _y);

    int GetLevelStatus(){ return levelStatus; }

    void updateTower(int rank);

    int getBackCoin();

    buildTowerBtn *btb = new buildTowerBtn;
protected:
    int *CoinStorage;

    int backCoin = 0;

    QString normalImgPath;
    QString changeImgPath;


    archeryTower *ar;
    magicTower *ma;
    int levelStatus = 0;
    int towerChoice = 0;
    int x, y;
private:
    QPixmap pix;
signals:

public slots:
};

#endif // UPDATE_BUILD_BUTTON_H
