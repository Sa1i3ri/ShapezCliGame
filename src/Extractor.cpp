//
// Created by 14832 on 2023/12/5.
//

#include "../header/Extractor.h"

Extractor::Extractor() : Equipment() {
    this->color = yellow;
    this->mineral = nullptr;
    this->type = extractor;
}

Extractor::Extractor(direction dir) {
    this->type = extractor;
    this->color = yellow;
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
