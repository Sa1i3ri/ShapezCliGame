//
// Created by 14832 on 2023/12/4.
//

#include "../header/Map.h"

Map::Map() {
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            this->board[i][j] = new NullObject();
        }
    }



}
