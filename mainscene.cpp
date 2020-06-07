#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    this->setFixedSize(1280,960);
    this->setWindowTitle("tower");
    this->setWindowIcon(QPixmap(":/Saved Pictures/AKKO.jpg"));

    //实例化选择关卡场景
        levelscene = new LevelScene;
        //监听选择关卡的返回按钮的信号
        connect(levelscene, &LevelScene::chooseSceneBack,[=](){
            this->setGeometry(levelscene->geometry());
            levelscene->hide();
            this->show();
        });


    //退出按钮的实现
        connect(ui->Quit, &QAction::triggered, [=](){
            this->close();
        });


    //开始按钮
        MyPushbutton *startBtn = new MyPushbutton(":/Saved Pictures/startBtn.png");
        startBtn->setParent(this);
        startBtn->move(101 , 609);

        connect(startBtn, &MyPushbutton::clicked,[=](){
            qDebug() << "startBtn clicked";
            //产生弹起特效
                startBtn->zoomDown();
                startBtn->zoomUp();

            //延时进入到选择关卡中
                QTimer::singleShot(300, this, [=](){
                    //设置levelScenen场景位置
                    levelscene->setGeometry(this->geometry());
                    this->hide();
                    levelscene->show();
                });
        });
}

void MainScene::paintEvent(QPaintEvent *)
{
    //设置背景图片
        QPainter painter(this);
        QPixmap pix;
        pix.load(":/Saved Pictures/mainScene.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


MainScene::~MainScene()
{
    delete ui;
}
