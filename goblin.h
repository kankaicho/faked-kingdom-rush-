#ifndef GOBLIN_H
#define GOBLIN_H

#include <QWidget>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QDebug>
#include "basicenemyinfo.h"

class Goblin : public QWidget, public BasicEnemyInfo
{
    Q_OBJECT
public:
    explicit Goblin(QWidget *parent = nullptr);

signals:
    void aliveSignals();
    void deathSignals();

public slots:
};

#endif // GOBLIN_H
