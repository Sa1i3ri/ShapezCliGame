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
#include "header/Timer.h"
void play(Window *window, Map *map){
    window->display(map);
    while (true){
        char input = getch();
        if(input =='w' || input=='s'||input=='a'||input=='d'){
            map->moveCursor(map->inputForMoveCursor(input));
            window->display(map);
            Sleep(10);
            continue;
        }
        if(input == '1' || input == '2' || input == '3' || input=='4' ||input=='5'|| input==' '||input=='r'){
            map->cursorInputChoose(input);
            window->display(map);
            Sleep(10);
            continue;
        }
        if(input == '0'){
            break;
        }

        if(input == 'p'){
            map->operateEverything();
            window->display(map);
        }

    }

}



void init(Window *window,Map *map){
    for(int i =0;i<H/5;i++){
        for(int j =0;j<W/5;j++){
            map->board[i][j] = new AMineral();
        }
    }

    for(int i =H/5;i< 2 * H/5;i++){
        for(int j =W/5;j< 2 * W/5 ;j++){
            map->board[i][j] = new BMineral();
        }
    }

    for(int i = H/2-1;i<=H/2+1;i++){
        for(int j = W/2-1;j<=W/2+1;j++){
            map->board[i][j]  = new Centre();
        }
    }


    map->cursor->containedObj = map->board[map->cursor->x][map->cursor->y];




}

void test(Window *window,Map *map, char input){
    window->display(map);
    if(input =='w' || input=='s'||input=='a'||input=='d'){
        map->moveCursor(map->inputForMoveCursor(input));
        window->display(map);
        Sleep(10);
        return;
    }
    if(input == '1' || input == '2' || input == '3' || input=='4' || input==' '||input=='r'){
        map->cursorInputChoose(input);
        window->display(map);
        Sleep(10);
        return;
    }
    if(input == '0'){
        return;
    }

    if(input == 'p'){
        map->operateEverything();
        window->display(map);
    }
}



int main(){
    Map *map = new Map();
    Window *window = new Window();
    init(window,map);



    play(window,map);


//    test(window,map,'2');
//    test(window,map,'r');
//    test(window,map,' ');
//    test(window,map,'d');
//
//    for(int i =0;i<10;i++){
//
//        test(window,map,'1');
//        test(window,map,'r');
//        test(window,map,' ');
//        test(window,map,'d');
//    }
//
//    window->display(map);
//
//    test(window,map,'p');
//    window->display(map);
//
//    test(window,map,'p');
//    window->display(map);

    Sleep(2000);
//    map->cursorInputChoose('3');
//    map->cursor->y  = 29;
//    map->cursorInputChoose(' ');
//    window->display(map);
    return 0;
}



