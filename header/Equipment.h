//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_EQUIPMENT_H
#define REALGAME_EQUIPMENT_H
#include "Object.h"
#include "Mineral.h"
#include "NullObject.h"
#include "NullMineral.h"



class Equipment : public Object {
public:


    direction dir;
    Mineral *mineral;
    int curTime;
    virtual void changeDirection(direction dir)=0;
};






#endif //REALGAME_EQUIPMENT_H
