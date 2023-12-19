//
// Created by 14832 on 2023/12/4.
//

#include "../../header/Tools/Window.h"

void Window::Set_Color(int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
}

void Window::display(Map *map) {
    system("cls");

    for(int i =0;i<Map::H;i++){
        for(int j =0;j<Map::W;j++){
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

    color(red);
    printf("Mission 1 : hand over 20 AMineral ");
    if(map->mission1){
        //任务1完成
        color(indigo);
        printf("Completed");
    }
    ::printf("\n");

    color(blue);
    printf("Mission 2 : hand over 30 BMineral ");
    if(map->mission2){
        //任务2完成
        color(indigo);
        printf("Completed");
    }
    ::printf("\n");

    color(purple);
    printf("Mission 3 : hand over 50 half AMineral ");
    if(map->mission3){
        //任务3完成
        color(indigo);
        printf("Completed");
    }
    ::printf("\n");

    color(white);
    ::printf("Extractor speed : %d\t",map->ExtractorInterval);
    ::printf("Transmission speed : %d\t",map->TransmissionBeltInterval);
    ::printf("Cutter speed : %d\t",map->CutterInterval);
    ::printf("\n");

    if(map->upGradeTimes>0){
        color(red);
        ::printf("Press Z to upgrade Extractor\t");
        color(blue);
        ::printf("Press X to upgrade TransmissionBelt\t");
        color(green);
        ::printf("Press C to upgrade Cutter\t");

        ::printf("\n");
    }

    color(indigo);
    printf("money: %d\n",map->money);
    color(red);
    printf("AMineral number : %d\n",map->AMineralNum);
    color(blue);
    printf("BMineral number: %d\n",map->BMineralNum);
    color(purple);
    printf("HalfAMineral number: %d\n",map->HalfAMineralNum);


//    color(white);
//    printf("use keyboard to choose\n");
    printf("\n");

    color(green);
    printf("1:Transmission belt ");
    color(yellow);
    printf("2:Extractor ");
    color(purple);
    printf("3:Cutter ");
    color(white);
    printf("4:Rubbish bin ");
    color(indigo);
    printf("5:cleaner ");
    printf("\n");

    color(white);
    printf("press p to continue\n");
    printf("press r to change direction\n");

    color(map->cursor->curObj->color);
    printf("%c",map->cursor->curObj->photo);


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




