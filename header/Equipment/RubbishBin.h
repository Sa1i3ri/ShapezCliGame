//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_RUBBISHBIN_H
#define REALGAME_RUBBISHBIN_H
#include "Equipment.h"



class RubbishBin: public Equipment{
public:
    RubbishBin();

    void changeDirection(direction dir)override;
};


#endif //REALGAME_RUBBISHBIN_H
