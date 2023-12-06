//
// Created by 14832 on 2023/12/4.
//

#include "../header/NullObject.h"

NullObject::NullObject() : Object() {
    this->color = white;
    this->photo = ' ';
    this->type = type::nullObject;
}
