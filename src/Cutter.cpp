//
// Created by 14832 on 2023/12/5.
//

#include "../header/Cutter.h"

Cutter::Cutter() {
    this->color = purple;
    this->mineral = new NullMineral();
    this->type = cutter;
}

Cutter::Cutter(direction dir, order ord) {
    this->type = cutter;
    this->color = purple;
    this->mineral = new NullMineral();
    this->dir = dir;
    this->ord = ord;
    this->curTime = 0;

    if(dir == direction::up){
        this->photo = '^';
    }else if(dir == direction::right){
        this->photo = '>';
    }else if(dir == direction::left){
        this->photo = '<';
    }else if(dir == direction::down){
        this->photo = '|';
    }
}

void Cutter::changeDirection(direction dir) {
    this->dir = dir;
    if(dir == direction::up){
        this->photo = '^';
    }else if(dir == direction::right){
        this->photo = '>';
    }else if(dir == direction::left){
        this->photo = '<';
    }else if(dir == direction::down){
        this->photo = '|';
    }
}
