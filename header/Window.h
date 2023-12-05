//
// Created by 14832 on 2023/12/4.
//

#ifndef REALGAME_WINDOW_H
#define REALGAME_WINDOW_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "Map.h"
#include "Object.h"
using namespace std;

class Window {
public:
    void Set_Color(int color);
    void color(int c);
    void display(Map *map);
};


#endif //REALGAME_WINDOW_H
