//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_CUTTER_H
#define REALGAME_CUTTER_H
#include "Equipment.h"
enum order{
    first,
    second
};
//当方向向上时，first的cutter位于左侧
//当方向向下时，first的cutter位于右侧
//当方向向左时，first的cutter位于下侧
//当方向向右时，first的cutter位于上侧


class Cutter: public Equipment{
public:
    order ord;
    Cutter();
    Cutter(direction dir,order ord);
};


#endif //REALGAME_CUTTER_H
