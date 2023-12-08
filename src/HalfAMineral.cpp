//
// Created by 14832 on 2023/12/7.
//

#include "../header/HalfAMineral.h"

HalfAMineral::HalfAMineral():AMineral() {
    this->photo = '+';
    this->value /=2;
    this->isCutble = false;
    this->color = red;
    this->type = type::halfAmineral;
}
