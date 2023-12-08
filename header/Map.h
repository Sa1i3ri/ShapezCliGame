//
// Created by 14832 on 2023/12/4.
//

#ifndef REALGAME_MAP_H
#define REALGAME_MAP_H
#include <bits/stdc++.h>  //众所周知的万能头
#include<windows.h>      //使用 Windows 提供的函数
#include<conio.h>        //使用 getch() 函数
#include "Object.h"
#include "TransmissionBelt.h"
#include "Extractor.h"
#include "RubbishBin.h"
#include "Cutter.h"
#include "AMineral.h"
#include "BMineral.h"
#include "HalfAMineral.h"
#include "Cursor.h"
#include "NullObject.h"
#include "Centre.h"
#include <vector>
using namespace std;


const int W = 30;
const int H = 30;

class Map {
private:
    void ExtractorOperate(int x,int y);
    void TransmissionBeltOperate(int x, int y,vector<TransmissionBelt*> *curTrans,vector<Equipment*> *ToDir);
    void Transmisson(vector<TransmissionBelt*> *curTrans,vector<Equipment*> *ToDir);
    void RubbishBinOperate(int x,int y);
    void CutterOperate(int x,int y);
    void CentreOperate(int x,int y);
    vector<int>* locateAnotherCutter(int x,int y,order ord,direction dir);
    void updateEquipmentCurTime(int x, int y);
public:
    Cursor *cursor;

    int overallValue;
    Object *board[W][H];
    Map();

    //检测输入移动光标
    direction inputForMoveCursor(char input);
    //检测输入调整光标代表的物体，并且检测是否放置
    void cursorInputChoose(char input);
    void moveCursor(direction dir);
    //TODO
    void operateEverything();


    void transmission();
};


#endif //REALGAME_MAP_H
