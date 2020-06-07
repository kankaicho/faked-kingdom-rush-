#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QMainWindow>
#include<QMenuBar>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include<QTimer>

#include "mypushbutton.h"
#include "level1.h"
#include "level2.h"

class LevelScene : public QMainWindow
{
    Q_OBJECT
public:
    Level1 *level1 = NULL;
    Level2 *level2 = NULL;

    explicit LevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

signals:
    //自定义信号，点击返回
    void chooseSceneBack();

public slots:
};

#endif // LEVELSCENE_H
