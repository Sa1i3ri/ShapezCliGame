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
#include "header/SavingFile.h"

Map *Level1Map = new Map();
Map *Level2Map = new Map();
Map *Level3Map = new Map();
MainInterface *mainInterface = new MainInterface();
Store *store = new Store();
Window *window = new Window();


Level *Level1 = new Level(LevelType::level1,Level1Map);
Level *Level2 = new Level(LevelType::level2,Level2Map);
Level *Level3 = new Level(LevelType::level3,Level3Map);



void play(Level *level){
    level->upgradeReInit();

    window->display(level->map);
    while (true){
        char input = getch();
        if(input =='w' || input=='s'||input=='a'||input=='d'){
            //移动光标
            level->map->moveCursor(level->map->inputForMoveCursor(input));
        }
        if(input == '1' || input == '2' || input == '3' || input=='4' ||input=='5'|| input==' '||input=='r'){
            //放置物品
            level->map->cursorInputChoose(input);
        }
        if(input == '0'){
            //退出
            return;
        }

        if(input == 'p'){
            //物品运作
            level->map->operateEverything();
        }

        if(input == 'z' || input == 'x' || input =='c'){
            //升级速率
            level->upgrade(input);
        }

        window->display(level->map);
        Sleep(10);

    }

}

void enterStore() {
    store->display();
    while (true) {
        char input = getch();
        if (input == '0') {
            return;
        }
        if (input == '1' || input == '2' || input=='3' || input=='4'||input=='5'||input=='6') {
            store->upgrade(input);
        }


        store->display();
    }
}

void init(){
    Level1->levelInit();
    Level1->mapInit();
    Level2->levelInit();
    Level2->mapInit();
    Level3->levelInit();
    Level3->mapInit();
}

void Interface(){
    mainInterface->display();
    while (true){
        char input = getch();
        if(input=='1' || input=='2' || input=='3' || input=='0' || input=='s'||input=='b'||input=='r'||input=='t'){
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

            //进入商店
            if(input == 's'){
                enterStore();
            }

            if(input=='b'){
                SavingFile::writeFile("../temp.csv",Level1,Level2,Level3);
            }

            if(input == 'r'){
                SavingFile::readFile("../temp.csv",Level1,Level2,Level3);
            }

            if(input=='t'){
                init();
            }



        }

        mainInterface->display();
        //Sleep(10);

    }
}








int main(){
    //SavingFile::readFile("../file.csv",Level1,Level2,Level3);

    //SavingFile::writeFile("../temp.csv",Level1,Level2->map,Level3->map);

    //SavingFile::readFile("../temp.csv",Level1,Level2,Level3);
    //play(Level1);
    Interface();
    //store->upgrade('4');
    //play(Level1);
    //SavingFile::read("../file.csv");


    //Sleep(2000);
    return 0;
}



