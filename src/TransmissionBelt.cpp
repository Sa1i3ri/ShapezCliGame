//
// Created by 14832 on 2023/12/5.
//

#include "../header/TransmissionBelt.h"

TransmissionBelt::TransmissionBelt() : Equipment() {
    this->color = green;
    this->mineral = nullptr;
    this->type = transmissionBelt;
}

TransmissionBelt::TransmissionBelt(direction dir) : Equipment() {
    this->color = green;
    this->type = transmissionBelt;
    this->mineral = nullptr;
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
