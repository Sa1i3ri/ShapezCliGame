//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_EQUIPMENT_H
#define REALGAME_EQUIPMENT_H
#include "Object.h"
#include "Mineral.h"
#include "NullObject.h"
#include "NullMineral.h"

//设置初始设备间隔
const int initExtractorInterval = 3,initTransmissionBeltInterval = 2,initRubbishBinInterval=1,initCutterInterval=3;

class Equipment : public Object {
public:
    //设置设备间隔
    static int ExtractorInterval;//3
    static int TransmissionBeltInterval;//2
    static int RubbishBinInterval;//1
    static int CutterInterval;//3

    direction dir;
    Mineral *mineral;
    int interval;
    int curTime;
    virtual void changeDirection(direction dir)=0;
};






#endif //REALGAME_EQUIPMENT_H
