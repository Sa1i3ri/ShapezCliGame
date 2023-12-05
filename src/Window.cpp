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
            color(map->board[i][j]->color);
            printf("%c",map->board[i][j]->photo);
        }
        cout<<endl;
    }

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
