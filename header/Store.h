//
// Created by 14832 on 2023/12/18.
//

#ifndef REALGAME_STORE_H
#define REALGAME_STORE_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "Level.h"
#include "Window.h"
#include "Map.h"
using namespace std;


class Store {
private:
    void displayTitle();
public:
    Map *map;
    Store(Map *map);
    void display();

    //全局升级
    void upgrade(char input);

};


#endif //REALGAME_STORE_H
