//
// Created by 14832 on 2023/12/4.
//

#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "header/Map.h"
#include "header/Object.h"
#include "header/Window.h"
#include "header/AMineral.h"
#include "header/BMineral.h"
#include "header/Centre.h"


void init(Map *map){
    for(int i =0;i<H/5;i++){
        for(int j =0;j<W/5;j++){
            map->board[i][j] = new AMineral();
        }
    }

    for(int i =H/5+1;i< H/5 *2;i++){
        for(int j =W/5+1;j<W/5 *2;j++){
            map->board[i][j] = new BMineral();
        }
    }

    for(int i = H/2-1;i<=H/2+1;i++){
        for(int j = W/2-1;j<=W/2+1;j++){
            map->board[i][j]  = new Centre();
        }
    }
}

void play(Window *window, Map *map){
    window->display(map);


}



int main(){
    Map *map = new Map();
    Window *window = new Window();
    init(map);
    play(window,map);
    Sleep(2000);
    return 0;
}



