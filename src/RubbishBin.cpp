//
// Created by 14832 on 2023/12/5.
//

#include "../header/RubbishBin.h"

RubbishBin::RubbishBin() : Equipment() {
    this->type = rubbishBin;
    this->color = white;
    this->photo = '*';
    this->mineral = nullptr;
}
