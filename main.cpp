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
#include "header/Level.h"
#include "header/MainInterface.h"
#include "header/Store.h"

Map *MainMap = new Map();
MainInterface *mainInterface = new MainInterface();
Store *store = new Store(MainMap);
Window *window = new Window();


Level *Level1 = new Level(LevelType::level1,MainMap);
Level *Level2 = new Level(LevelType::level2,MainMap);
Level *Level3 = new Level(LevelType::level3,MainMap);



void play(Level *level){
    level->LevelLoad();

    window->display(MainMap);
    while (true){
        char input = getch();
        if(input =='w' || input=='s'||input=='a'||input=='d'){
            //移动光标
            MainMap->moveCursor(MainMap->inputForMoveCursor(input));
        }
        if(input == '1' || input == '2' || input == '3' || input=='4' ||input=='5'|| input==' '||input=='r'){
            //放置物品
            MainMap->cursorInputChoose(input);
        }
        if(input == '0'){
            //退出
            return;
        }

        if(input == 'p'){
            //物品运作
            MainMap->operateEverything();
        }

        if(input == 'z' || input == 'x' || input =='c'){
            //升级速率
            level->upgrade(input);
        }

        window->display(MainMap);
        Sleep(10);

    }

}

void enterStore() {
    store->display();
    while (true) {
        char input = getch();
        if (input == '0') {
            if (input == '0') {
                return;
            }
        }
        store->display();
    }
}

void Interface(){
    mainInterface->display(MainMap);
    while (true){
        char input = getch();
        if(input=='1' || input=='2' || input=='3' || input=='0' || input=='s'){
            if(input=='0'){
                return;
            }
            //选关
            if(input=='1'){
                play(Level1);
            }else if(input=='2'){
                play(Level2);
            }else if(input=='3'){
                play(Level3);
            }

            if(input == 's'){
                enterStore();
            }

            //进入商店

        }

        mainInterface->display(MainMap);
        //Sleep(10);

    }
}






int main(){


    //play(window,MainMap,Level2);
    Interface();


    Sleep(2000);

    return 0;
}



