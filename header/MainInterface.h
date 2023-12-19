//
// Created by 14832 on 2023/12/13.
//

#ifndef REALGAME_MAININTERFACE_H
#define REALGAME_MAININTERFACE_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "Level.h"
#include "Window.h"
#include "Store.h"
#include "Map.h"

using namespace std;




class MainInterface {
private:
    void displayTitle();
public:
    MainInterface();

    void display();




};


#endif //REALGAME_MAININTERFACE_H
