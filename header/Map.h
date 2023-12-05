//
// Created by 14832 on 2023/12/4.
//

#ifndef REALGAME_MAP_H
#define REALGAME_MAP_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "Object.h"
#include "NullObject.h"
#include "Centre.h"
#include <vector>
using namespace std;


const int W = 50;
const int H = 50;

class Map {
public:
    int overallValue;
    Object *board[W][H];
    Map();
};


#endif //REALGAME_MAP_H
