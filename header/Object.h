//
// Created by 14832 on 2023/12/4.
//

#ifndef REALGAME_OBJECT_H
#define REALGAME_OBJECT_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数

const int blue=0,yellow=1,red=2,green=3,purple=4,white=5,indigo=6;//颜色常量

enum direction{
    up,
    down,
    left,
    right,
};

enum type{
    extractor,
    transmissionBelt,
    cutter,
    rubbishBin,
    Amineral,
    Bmineral,
    centre,
    nullObject,
    nullMineral,
    halfAmineral,
    halfBmineral,
};


class Object {
public:
    type type;
    int color;
    char photo;

};


#endif //REALGAME_OBJECT_H
