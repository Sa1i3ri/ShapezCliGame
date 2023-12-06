//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_EQUIPMENT_H
#define REALGAME_EQUIPMENT_H
#include "Object.h"
#include "Mineral.h"
#include "NullObject.h"
#include "NullMineral.h"

//设置设备间隔
const int ExtractorInterval = 3 , TransmissionBeltInterval = 1,RubbishBinInterval = 2,CutterInterval = 3;

class Equipment : public Object {
public:
    direction dir;
    Mineral *mineral;
    int interval;
    int curTime;
    virtual void changeDirection(direction dir)=0;
};


#endif //REALGAME_EQUIPMENT_H
