//
// Created by 14832 on 2023/12/13.
//

#ifndef REALGAME_LEVEL_H
#define REALGAME_LEVEL_H

#include "Map.h"

//设置初始设备间隔
const int initExtractorInterval = 3,initTransmissionBeltInterval = 2,initRubbishBinInterval=1,initCutterInterval=3;

enum LevelType{
    level1,
    level2,
    level3,
    nullLevel,
};


class Level {
private:
    static Object* translation(type ObjectType);
    void fromLevelToMap();

    void LevelNull();
    void Level1();
    void Level2();
    void Level3();
    //把board写到map上
    void initMap();

public:
    double CentreSize;

    Map *map;
    LevelType levelType;
    //对应map的type
    //type board[Map::H][Map::W]{};
    vector<vector<type>> board;


    Level(LevelType levelType);
    Level(LevelType levelType,Map *map);
    explicit Level(Map *map);
    Level();

    //布置矿物
    void deployMineral(int i,int j,type type);
    //包含start，不包括end，左闭右开
    void wideScaleDeploy(int start_i,int end_i,int start_j,int end_j,int offset,type type);

    //把关卡画到board上
    void levelInit();
    //初始化地图，把level画到map上
    void mapInit();
    //如果升级了，把关卡画到board上，并且再写到map上
    void upgradeReInit();
    //局内升级
    void upgrade(char input);

    //根据当前H和W，设定地图大小
    void sizeMap();

};


#endif //REALGAME_LEVEL_H
