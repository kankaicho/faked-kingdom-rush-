#ifndef BASICINFO_H
#define BASICINFO_H

#include <QString>

//TowerChooseLoc
const int archeryStart_X = 0;
const int archeryEnd_X = 65;
const int archeryStart_Y = 0;
const int archeryEnd_Y = 80;
const int magicStart_X = 0;
const int magicEnd_X = 65;
const int magicStart_Y = 120;
const int magicEnd_Y = 200;

//ArcheryTower Level Information
const int archeryTowerAttackRange[4] = {1,500,600,700};
const int archeryTowerAttackSpeed[4] = {9999999,50,55,60};
const int archeryTowerPerDamage[4] = {0,15,25,40};
const int archeryTowerBuildCost[4] = {0,70,90,110};
const int archeryTowerDamageCost[4] = {0,50,110,180};


//MagicTower Level Information
const int magicTowerAttackRange[4] = {1, 280, 315, 350 };
const int magicTowerAttackSpeed[4] = {9999999, 50, 55, 60};
const int magicTowerPerdamage[4] = {0, 25, 50, 80};
const int magicTowerBuildCost[4] = {0, 100, 180, 280};
const int magicTowerDamageCost[4] = {0, 70, 155, 260};

//Level1 Information
    //Level1 TowerBtn Location
const int Level1TowerNumber = 9;
const int Level1Loc_X[Level1TowerNumber] = {175, 360, 308, 498, 690, 720, 1025, 925, 1005};
const int Level1Loc_Y[Level1TowerNumber] = {520, 375, 595, 504, 500, 690, 255,  570, 660 };


//Level2 Information
const int Level2TowerNumber = 11;
const int Level2Loc_X[Level2TowerNumber] = {365, 595, 680, 860, 850, 310, 240, 430, 590, 820, 970};
const int Level2Loc_Y[Level2TowerNumber] = {280, 300, 200, 160, 320, 470, 670, 660, 740, 690, 670};

    //Level1 Monster Path
const int Path1X[6] = {1280, 970, 820, 490, 230, 0  };
const int Path1Y[6] = {200,  175, 600, 600, 430, 500};

const int Path2X[5] = {1280, 800, 500, 250, 0  };
const int Path2Y[5] = {750,  610, 610, 440, 500};




//Monster
const int GnollHP = 250;
const int GnollSpeed = 2;
const int GnollDeathCoin = 10;
const int GnollEnterDamage = 1;
const int GnollInitialLocX = Path1X[0];
const int GnollInitialLocY = Path1Y[0];
const QString GnollImage = ":/Saved Pictures/Gnoll.png";


const int OrgeHP = 1500;
const int OrgeSpeed = 1;
const int OrgeDeathCoin = 40;
const int OrgeEnterDamage = 2;
const int OrgeInitialLocX = Path2X[0];
const int OrgeInitialLocY = Path2Y[0];
const QString OrgeImage = ":/Saved Pictures/Orge.png";

















#endif // BASICINFO_H
