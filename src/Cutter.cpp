//
// Created by 14832 on 2023/12/5.
//

#include "../header/Cutter.h"

Cutter::Cutter() {
    this->color = purple;
    this->mineral = nullptr;
    this->type = cutter;
}

Cutter::Cutter(direction dir, order ord) {
    this->type = cutter;
    this->color = yellow;
    this->mineral = nullptr;
    this->dir = dir;
    this->ord = ord;
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
