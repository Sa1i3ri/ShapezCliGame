//
// Created by 14832 on 2023/12/5.
//

#include "../header/Cursor.h"

Cursor::Cursor() {
    this->x =0;
    this->y=0;
    this->color = indigo;
    this->containedObj = new NullMineral();
    this->curObj = new NullObject();
}



