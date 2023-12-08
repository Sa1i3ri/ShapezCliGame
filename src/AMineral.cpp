//
// Created by 14832 on 2023/12/4.
//

#include "../header/AMineral.h"

AMineral::AMineral() : Mineral() {
    this->isCutble = true;
    this->color = red;
    this->photo = '#';
    this->value = 2;
    this->type = type::Amineral;
}
