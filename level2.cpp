#include "level2.h"


Level2::Level2(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1280, 960);
    this->setWindowIcon(QPixmap(":/Saved Pictures/AKKO.jpg"));
    this->setWindowTitle("level2");

    initialLocBtnAndTower();

    //设置状态
    status->setParent(this);
    QFont statusFont;
    statusFont.setFamily("华文新魏");
    statusFont.setPointSize(14);
    status->setFont(statusFont);
//    QString str = QString("coin: %1  health: %1").arg(Coin).arg(health);
//    status->setText(str);
    status->setGeometry(300, 100, 240, 80);


    //返回按钮实现
        MyPushbutton *backBtn = new MyPushbutton(":/Saved Pictures/quitBtn.png",":/Saved Pictures/quitBtn2.png");
        backBtn->setParent(this);
        backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
        connect(backBtn, &MyPushbutton::clicked, [=](){
            qDebug() << "level1 backBtn pressed";
            QTimer::singleShot(200, this, [=](){
                emit this->level1Back();
            });
        });



        //建造按钮/*test*/
        for(int i = 0; i < Level2TowerNumber; i ++)
        {
            locBtn[i]->setParent(this);
            locBtn[i]->move(Level2Loc_X[i], Level2Loc_Y[i]);
            locBtn[i]->setLoc(Level2Loc_X[i], Level2Loc_Y[i]);

            connect(locBtn[i], &update_build_button::clicked, [=](){

                    if(!locBtn[i]->GetLevelStatus())
                    {
                        bbb[i]->move(Level2Loc_X[i] - 47, Level2Loc_Y[i] - 70);
                        connect(bbb[i], &buildTowerBtn::clicked, [=](){
                            if(bbb[i]->getTowerType() == 1)
                            {
                                locBtn[i]->getTowerArchery(archery[i], bbb[i]->getTowerType());
                                bbb[i]->move(-200, -200);
                            }
                            else if(bbb[i]->getTowerType() == 2)
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
                    qDebug() << "locBtn clicked";

                Coin -= archery[i]->buildCost;
                Coin -= magic[i]->buildCost;
                QString str = QString("coin: %1  health: %2").arg(this->Coin).arg(this->health);
                status->setText(str);

            });
        }


        /*怪物测试*/
        MyPushbutton *startBtn = new MyPushbutton(":/Saved Pictures/startBtn.png");
        startBtn->setParent(this);
        startBtn->move(0, 0);
        connect(startBtn, &MyPushbutton::clicked, [=](){
            timer1->start(100);
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
                for(int j = 0; j < Level2TowerNumber; j ++)
                {
                    archery[j]->temInterval += 5;
                    if(archery[j]->temInterval >= archery[j]->attackSpeed)
                    {
                        for(int i = 0; i < 10; i ++)
                        {
                            if(testmonster[j].m_Rect.intersects(archery[j]->judgeRect) && testmonster[i].isAlive)
                            {
                                archery[j]->shoot(testmonster[i].mX, testmonster[i].mY);
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
                        archery[j]->temInterval = 0;
                    }
                }

                for(int j = 0; j < Level2TowerNumber; j ++)
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


                //显示coin和health状态
                QString str = QString("coin: %1  health: %2").arg(this->Coin).arg(this->health);
                status->setText(str);

                update();
            });
        });

}


void Level2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Saved Pictures/Level2Scene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    for(int i = 0; i < Level1TowerNumber; i ++)
    {
        if(archery[i]->onAttackStatus)
        {
            archery[i]->paintBullet(painter);
            archery[i]->onAttackStatus = false;
        }
        for(int i = 0; i < Level1TowerNumber; i ++)
        {
            if(magic[i]->onAttackStatus)
            {
                magic[i]->paintBullet(painter);
                magic[i]->onAttackStatus = false;
            }
        }

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
}



void Level2::showEnemy()
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

void Level2::showEndScene()
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

void Level2::initialLocBtnAndTower()
{

    timer1 = new QTimer(this);
    for(int i = 0; i < Level2TowerNumber; i ++)
    {
        magic[i] = new magicTower(Level2Loc_X[i], Level2Loc_Y[i]);
        archery[i] = new archeryTower(Level2Loc_X[i], Level2Loc_Y[i]);
        locBtn[i] = new update_build_button();

        bbb[i] = new buildTowerBtn;
        bbb[i]->setParent(this);
        bbb[i]->move(-200, -200);
    }
}
