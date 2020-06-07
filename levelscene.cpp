#include "levelscene.h"

LevelScene::LevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
        this->setFixedSize(1280,960);
        this->setWindowIcon(QPixmap(":/Saved Pictures/AKKO.jpg"));
        this->setWindowTitle("LevelScene");

    //创建菜单栏
        QMenuBar *bar = menuBar();
        setMenuBar(bar);
        QMenu *startMenu = bar->addMenu("tool");
        QAction * quitAction = startMenu->addAction("quit");
        connect(quitAction, &QAction::triggered, [=](){
            this->close();
        });

    //返回按钮
        MyPushbutton *BackBtn = new MyPushbutton(":/Saved Pictures/quitBtn.png",":/Saved Pictures/quitBtn2.png");
        BackBtn->setParent(this);
        BackBtn->move(0, this->height()- BackBtn->height());

        connect(BackBtn, &MyPushbutton::clicked,[=](){
            qDebug() << "backBtn clicked";
            QTimer::singleShot(200, this, [=](){
                emit this->chooseSceneBack();
            });

        });

    //关卡按钮
        MyPushbutton *level1Btn = new MyPushbutton(":/Saved Pictures/levelSceneChooseButton.png");
        MyPushbutton *level2Btn = new MyPushbutton(":/Saved Pictures/levelSceneChooseButton.png");
        level1Btn->setParent(this);
        level2Btn->setParent(this);
        level1Btn->move(145,154);
        level2Btn->move(390,251);
        level1 = new Level1;
        level2 = new Level2;

        //监听level1的返回按钮
        connect(level1, &Level1::level1Back, [=](){
            this->setGeometry(level1->geometry());
            level1->hide();
            this->show();
        });

        //监听level2的返回按钮
        connect(level2, &Level2::level1Back, [=](){
            this->setGeometry(level2->geometry());
            level2->hide();
            this->show();
        });

        connect(level1Btn, &MyPushbutton::clicked, [=](){
            level1Btn->zoomDown();
            level1Btn->zoomUp();
            QTimer::singleShot(200,this,[=](){
                level1->setGeometry(this->geometry());
                this->hide();
                level1->show();
            });
        });

        connect(level2Btn, &MyPushbutton::clicked, [=](){
            level2Btn->zoomDown();
            level2Btn->zoomUp();
            QTimer::singleShot(200,this,[=](){
                level2->setGeometry(this->geometry());
                this->hide();
                level2->show();
            });
        });
}

void LevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Saved Pictures/levelScene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
