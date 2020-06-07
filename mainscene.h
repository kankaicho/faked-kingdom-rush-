#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include<QTimer>

#include "levelscene.h"
#include "mypushbutton.h"

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void paintEvent(QPaintEvent *);

    LevelScene *levelscene = NULL;


private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
