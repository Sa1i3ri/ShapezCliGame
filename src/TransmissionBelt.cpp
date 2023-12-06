//
// Created by 14832 on 2023/12/5.
//

#include "../header/TransmissionBelt.h"


TransmissionBelt::TransmissionBelt(direction dir) : Equipment() {
    this->color = green;
    this->type = transmissionBelt;
    this->mineral = new NullMineral();
    this->dir = dir;
    this->interval  = TransmissionBeltInterval;
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

void TransmissionBelt::changeDirection(direction dir) {
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
