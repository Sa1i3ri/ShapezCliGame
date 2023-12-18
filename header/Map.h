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


//const int W = 30;
//const int H = 20;

//任务目标
const int AMineralTarget = 20, BMineralTarget = 30, HalfAMineralTarget = 50;


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
    void AMineralMission(Centre *curCentre);
    void BMineralMission(Centre *curCentre);
    void HalfAMineralMission(Centre *curCentre);
    void missionsJudge(int x,int y);
public:
    //地图大小
    static int H;
    static int W;
    Cursor *cursor;

    //玩家开采的数量
    int overallValue;
    int AMineralNum;
    int HalfAMineralNum;
    int BMineralNum;

    //是否完成任务目标
    bool mission1;
    bool mission2;
    bool mission3;
    //是否要进行升级
    //bool isUpgrade;
    int upGradeTimes;

    //全局升级
    int CentreSize= 1;// (1 + 2 * CentreSize) * (1 + 2 * CentreSize)

    //Object *board[H][W];
    vector<vector<Object*>> board;
    Map();
    //初始化地图
    void initMap();

    //检测输入移动光标
    direction inputForMoveCursor(char input);
    //检测输入调整光标代表的物体，并且检测是否放置
    void cursorInputChoose(char input);
    void moveCursor(direction dir);
    //所有场景物件动一次
    void operateEverything();





    void transmission();
};


#endif //REALGAME_MAP_H
