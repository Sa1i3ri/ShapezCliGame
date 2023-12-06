//
// Created by 14832 on 2023/12/4.
//

#include "../header/Window.h"

void Window::Set_Color(int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
}

void Window::display(Map *map) {
    system("cls");


    for(int i =0;i<H;i++){
        for(int j =0;j<W;j++){
            //打印光标
            if(i == map->cursor->x && j == map->cursor->y){
                color(map->cursor->color);
                if(map->cursor->containedObj->photo == ' '){
                    printf(".");
                }else{
                    printf("%c",map->cursor->containedObj->photo);
                }

                continue;
            }
            //如果传送带上有矿物，打印出来的应该是矿物的photo

            if(map->board[i][j]->type == type::transmissionBelt){
                auto curTrans = (TransmissionBelt *)map->board[i][j];
                if(curTrans->mineral->type != type::nullMineral){
                    color(curTrans->mineral->color);
                    printf("%c",curTrans->mineral->photo);
                    continue;
                }
            }



            color(map->board[i][j]->color);
            printf("%c",map->board[i][j]->photo);
        }
        cout<<endl;
    }
    color(white);
    printf("use keyboard to choose\n");
    color(green);
    printf("1:Transmission belt ");
    color(yellow);
    printf("2:Extractor ");
    color(purple);
    printf("3:Cutter ");
    color(white);
    printf("4:Rubbish bin");
    printf("\n");
    printf("press p to continue\n");
    printf("press r to change direction\n");

    ::printf("%c",map->cursor->curObj->photo);

}

void Window::color(int c) {
    switch(c)
    {
        case red:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);break;  //红色原色
        case green:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);break;  //绿色原色
        case yellow:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);break;  //黄色：红色和绿色相加
        case blue:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);break;  //蓝色原色
        case white:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);break;  //白色：三原色相加
        case purple:SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);break;  //紫色：红色和蓝色相加
        case indigo : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE|FOREGROUND_GREEN);break;
    }
}
