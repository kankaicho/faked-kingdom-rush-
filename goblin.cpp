#include "goblin.h"

Goblin::Goblin(QWidget *parent) : QWidget(parent)
{
    this->aliveJudgement = 1;
    this->speed = 100;
    this->HP = 20;
    this->physicalResistance = 0;
    this->magicResistance = 10;
}
