//
// Created by 14832 on 2023/12/5.
//

#include "../../header/Equipment/Extractor.h"

Extractor::Extractor() : Equipment() {
    this->color = yellow;
    this->mineral = new NullMineral();
    this->type = extractor;
    this->curTime = 0;
}

Extractor::Extractor(direction dir) {
    this->type = extractor;
    this->color = yellow;
    this->mineral = nullptr;
    this->dir = dir;
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

void Extractor::deploy(Object *obj) {
    if(obj->type == type::Amineral || obj->type == type::Bmineral){
        this->mineral =(Mineral *) obj;
    }

}

void Extractor::changeDirection(direction dir) {
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
