//
// Created by 14832 on 2023/12/4.
//

#ifndef REALGAME_CENTRE_H
#define REALGAME_CENTRE_H
#include "Equipment.h"
#include "../Mineral/NullMineral.h"


class Centre: public Equipment{


public:

    Centre();
    void changeDirection(direction dir)override;

};



#endif //REALGAME_CENTRE_H
