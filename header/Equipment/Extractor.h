//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_EXTRACTOR_H
#define REALGAME_EXTRACTOR_H
#include "Equipment.h"
#include "../Mineral/NullMineral.h"



class Extractor: public Equipment{
public:

    Extractor();
    Extractor(direction dir);
    void deploy(Object *obj);

    void changeDirection(direction dir)override;
};


#endif //REALGAME_EXTRACTOR_H
