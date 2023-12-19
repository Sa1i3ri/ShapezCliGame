//
// Created by 14832 on 2023/12/4.
//

#include "../header/Centre.h"

Centre::Centre() {
    this->color = white;
    this->photo = '@';
    this->type = type::centre;
    this->curTime =0;
    this->mineral = new NullMineral();
    this->dir = direction::up;
}

void Centre::changeDirection(direction dir) {
    return;
}


