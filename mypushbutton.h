#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include<QMouseEvent>
#include<QDebug>
#include "buildtowerbtn.h"
#include "archerytower.h"
#include "magictower.h"
#include "basictowerinfo.h"

class MyPushbutton : public QPushButton
{
    Q_OBJECT
public:

    MyPushbutton(QString normalImg, QString pressImg = "");

    void zoomUp();
    void zoomDown();
    void mousePressEvent(QMouseEvent *ev);

    void mouseReleaseEvent(QMouseEvent *ev);


protected:
    QString normalImgPath;
    QString pressImgPath;
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
