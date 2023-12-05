//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_EQUIPMENT_H
#define REALGAME_EQUIPMENT_H
#include "Object.h"
#include "Mineral.h"
enum equipment{
    extractor,
    transmissionBelt,
    cutter,
    rubbishBin,
};


class Equipment : public Object {
public:
    equipment type;
    direction dir;
    Mineral *mineral;
};


#endif //REALGAME_EQUIPMENT_H
