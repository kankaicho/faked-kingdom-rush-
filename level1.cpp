#include "level1.h"

Level1::Level1(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1280, 960);
    this->setWindowIcon(QPixmap(":/Saved Pictures/AKKO.jpg"));
    this->setWindowTitle("level1");

    initialLocBtnAndTower();

    //返回按钮实现
        connect(backBtn, &MyPushbutton::clicked, [=](){
            qDebug() << "level1 backBtn pressed";
            QTimer::singleShot(200, this, [=](){
                emit this->level1Back();
            });
        });


        //建造按钮/*test*/
        for(int i = 0; i < Level1TowerNumber; i ++)
        {
            connect(locBtn[i], &update_build_button::clicked, [=](){
                    if(locBtn[i]->GetLevelStatus() == 0)
                    {
                        bbb[i]->move(Level1Loc_X[i] - 47, Level1Loc_Y[i] - 70);

                        connect(bbb[i], &buildTowerBtn::clicked, [=](){
                            if(bbb[i]->getTowerType() == 1 && this->Coin >= archery[i]->buildCost)
                            {
                                locBtn[i]->getTowerArchery(archery[i], bbb[i]->getTowerType());
                                bbb[i]->move(-200, -200);
                            }

                            else if(bbb[i]->getTowerType() == 2 && this->Coin >= magic[i]->buildCost)
                            {
                                locBtn[i]->getTowerMagic(magic[i], bbb[i]->getTowerType());
                                bbb[i]->move(-200, -200);
                            }

                            else if(bbb[i]->getTowerType() == 0)
                            {
                                bbb[i]->move(-200, -200);
                            }
                        });
                    }

                    Coin -= archery[i]->buildCost;
                    Coin -= magic[i]->buildCost;
                    QString str = QString("coin: %1  health: %2").arg(this->Coin).arg(this->health);
                    status->setText(str);
            });
        }


        /*怪物测试*/
        connect(startBtn, &MyPushbutton::clicked, [=](){
            timer1->start(10);
            connect(timer1, &QTimer::timeout, [=](){
                showEnemy();
                for(int i = 0; i < 10; i ++)
                {
                    testmonster[i].updatePosition();
                    if(testmonster[i].enterDirection && !testmonster[i].causeDamage)
                    {
                        this->health -= testmonster[i].enterDamage;
                        showEndScene();
                        testmonster[i].causeDamage = true;
                    }
                }

                for(int i = 0; i < 5 ; i ++)
                {
                    testmonster2[i].updatePosition();
                    if(testmonster2[i].enterDirection && !testmonster2[i].causeDamage)
                    {
                        this->health -= testmonster2[i].enterDamage;
                        showEndScene();
                        testmonster2[i].causeDamage = true;
                    }
                }

                //攻击判断
                for(int j = 0; j < Level1TowerNumber; j ++)
                {
                    archery[j]->temInterval += 5;
                    if(archery[j]->temInterval >= archery[j]->attackSpeed)
                    {
                        for(int i = 0; i < 10; i ++)
                        {
                            if(archery[j]->judgeRect.intersects(testmonster[i].m_Rect) && testmonster[i].isAlive)
                            {
                                archery[j]->shoot(testmonster[i].mX, testmonster[i].mY);
                                qDebug() << "Attack!!!";
                                testmonster[i].HP -= archery[j]->perDamage;
                                if(testmonster[i].HP <= 0)
                                {
                                    this->Coin += testmonster[i].deathCoin;
                                    testmonster[i].isAlive = false;
                                    testmonster[i].isFree = true;
                                    enemyNumber --;
                                    showEndScene();
                                }
                                archery[j]->temInterval = 0;
                                break;
                            }
                        }
                    }
                }

                for(int j = 0; j < Level1TowerNumber; j ++)
                {
                    magic[j]->temInterval += 5;
                    if(magic[j]->temInterval >= magic[j]->attackSpeed)
                    {
                        for(int i = 0; i < 10; i ++)
                        {
                            if(testmonster[j].m_Rect.intersects(magic[j]->judgeRect) && testmonster[i].isAlive)
                            {
                                magic[j]->shoot(testmonster[i].mX, testmonster[i].mY);
                                testmonster[i].HP -= archery[j]->perDamage;
                                if(testmonster[i].HP <= 0)
                                {
                                    this->Coin += testmonster[i].deathCoin;
                                    testmonster[i].isAlive = false;
                                    testmonster[i].isFree = true;
                                    enemyNumber --;
                                    showEndScene();
                                }
                                break;
                            }
                        }
                        magic[j]->temInterval = 0;
                    }
                }


                QString str = QString("coin: %1  health: %2").arg(this->Coin).arg(this->health);
                status->setText(str);
                update();
            });
        });

}


void Level1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Saved Pictures/level1Scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    for(int i = 0; i < Level1TowerNumber; i ++)
    {
        painter.drawRect(archery[i]->judgeRect);
        painter.drawRect(magic[i]->judgeRect);
    }

    for(int i = 0; i < 10; i ++)
    {
        painter.drawRect(testmonster[i].m_Rect);
    }

    for(int i = 0; i < Level1TowerNumber; i ++)
    {
        if(archery[i]->onAttackStatus)
        {
            archery[i]->paintBullet(painter);
            archery[i]->onAttackStatus = false;
        }

        if(magic[i]->onAttackStatus)
        {
            magic[i]->paintBullet(painter);
            magic[i]->onAttackStatus = false;
        }

        if(magic[i]->built)  painter.drawPixmap(Level1Loc_X[i], Level1Loc_Y[i], magic[i]->towerImg.width(), magic[i]->towerImg.height(), magic[i]->towerImg);
        if(archery[i]->built)  painter.drawPixmap(Level1Loc_X[i], Level1Loc_Y[i], archery[i]->towerImg.width(), archery[i]->towerImg.height(), archery[i]->towerImg);
    }

    for(int i = 0; i < 10; i ++)
    {
        if(testmonster[i].isFree == false)
            painter.drawPixmap(testmonster[i].mX, testmonster[i].mY,testmonster[i].m_pixmap.width(),testmonster[i].m_pixmap.height(), testmonster[i].m_pixmap);
    }

    for(int i = 0; i < 5; i ++)
    {
        if(testmonster2[i].isFree == false)
            painter.drawPixmap(testmonster2[i].mX, testmonster2[i].mY,testmonster2[i].m_pixmap.width(),testmonster2[i].m_pixmap.height(), testmonster2[i].m_pixmap);
    }

//    for(int i = 0; i < currentEnemyNumber; i ++)
//    {
//        if(finalEnemy[i]->isFree == false)
//            painter.drawPixmap(finalEnemy[i]->mX, finalEnemy[i]->mY, finalEnemy[i]->m_pixmap.width(),finalEnemy[i]->m_pixmap.height(),finalEnemy[i]->m_pixmap);
//    }
}

int Level1::getMonsterType()
{
    int type = rand()%3;
    return type;
}

void Level1::showEnemy()
{
    currentTime ++;

    if(currentTime == timeInterval)
    {
        currentTime = 0;
        for(int i = 0; i < 10; i ++)
        {
            if(testmonster[i].isFree && testmonster[i].isAlive && (!testmonster[i].enterDirection))
            {
                testmonster[i].isFree = false;
                testmonster[i].mX = Path1X[0];
                testmonster[i].mY = Path1Y[0];
                break;
            }
        }

        for(int i = 0; i < 5 ; i ++)
        {
            if(testmonster2[i].isFree && testmonster2[i].isAlive && (!testmonster2[i].enterDirection))
            {
                testmonster2[i].isFree = false;
                testmonster2[i].mX = Path2X[0];
                testmonster2[i].mY = Path2Y[0];
                break;
            }
        }
    }
}

void Level1::showEndScene()
{
    QLabel *winLabel = new QLabel;
    QPixmap temPix;
    temPix.load(":/Saved Pictures/KAR.jpg");
    winLabel->setGeometry(0, 0, temPix.width(), temPix.height());
    winLabel->setPixmap(temPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - temPix.width()) * 0.5, -temPix.height());
    if(enemyNumber <= 0 || health <= 6)
    {

        QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(winLabel->x(), winLabel->y(), winLabel->width(), winLabel->height()));
        animation->setEndValue(QRect(winLabel->x(), winLabel->y() + winLabel->height() * 2, winLabel->width(), winLabel->height()));
        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start();
    }
}

void Level1::initialLocBtnAndTower()
{
    backBtn = new MyPushbutton(":/Saved Pictures/quitBtn.png",":/Saved Pictures/quitBtn2.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    startBtn = new MyPushbutton(":/Saved Pictures/startBtn.png");
    startBtn->setParent(this);
    startBtn->move(0, 0);

    timer1 = new QTimer(this);
    for(int i = 0; i < Level1TowerNumber; i ++)
    {
        magic[i] = new magicTower(Level1Loc_X[i], Level1Loc_Y[i]);
        archery[i] = new archeryTower(Level1Loc_X[i], Level1Loc_Y[i]);
        locBtn[i] = new update_build_button();
        locBtn[i]->setParent(this);
        locBtn[i]->move(Level1Loc_X[i], Level1Loc_Y[i]);
        locBtn[i]->setLoc(Level1Loc_X[i], Level1Loc_Y[i]);
        bbb[i] = new buildTowerBtn;
        bbb[i]->setParent(this);
        bbb[i]->move(-200, -200);
    }

    //设置HP,Coin状态显示信息
    status->setParent(this);
    QFont statusFont;
    statusFont.setFamily("华文新魏");
    statusFont.setPointSize(14);
    status->setFont(statusFont);
    QString str = QString("coin: %1  health: %1").arg(Coin).arg(health);
    status->setText(str);
    status->setGeometry(300, 100, 240, 80);

}

