//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_CURSOR_H
#define REALGAME_CURSOR_H
#include "../Object.h"
#include "../Equipment/TransmissionBelt.h"
#include "../NullObject.h"


class Cursor {
public:
    int x;
    int y;
    int color;
    //现在光标所要放置的Object
    Object *curObj;
    //光标所在的map上的Object
    Object *containedObj;
    Cursor();

};


#endif //REALGAME_CURSOR_H
