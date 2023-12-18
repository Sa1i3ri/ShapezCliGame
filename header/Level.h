//
// Created by 14832 on 2023/12/13.
//

#ifndef REALGAME_LEVEL_H
#define REALGAME_LEVEL_H

#include "Map.h"


enum LevelType{
    level1,
    level2,
    level3,
    nullLevel,
};


class Level {
private:
    static Object* translation(type ObjectType);

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

    //把关卡画到board上，并且再写到map上
    void LevelLoad();
    //局内升级
    void upgrade(char input);

};


#endif //REALGAME_LEVEL_H
