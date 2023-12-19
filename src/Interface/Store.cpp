//
// Created by 14832 on 2023/12/18.
//

#include "../../header/Interface/Store.h"

Store::Store() {
}

void Store::display() {
    system("cls");

    displayTitle();

    Window::color(white);
    printf("Press 1 to enlarge Centre,need money:%d,current size:%d\n",enlargeCentre,Map::CentreSize);

    Window::color(red);
    printf("Press 2 to enlarge AMineral,need money:%d,current size:%d\n",enlargeAMineral,Map::AMineralSize);

    Window::color(blue);
    printf("Press 3 to enlarge BMineral,need money:%d,current size:%d\n",enlargeBMineral,Map::BMineralSize);

    Window::color(yellow);
    printf("Press 4 to enlarge Map,need money:%d,current H:%d,current W:%d\n",enlargeMap,Map::H,Map::W);

    Window::color(red);
    printf("Press 5 to increase AMineral value,need money:%d,current AMineral value:%d\n",increaseAMineralValue,Mineral::AMineralValue);

    Window::color(blue);
    printf("Press 6 to increase BMineral value,need money:%d,current BMineral value:%d\n",increaseBMineralValue,Mineral::BMineralValue);

    Window::color(white);
    ::printf("Money : %d",Map::money);


}

void Store::displayTitle() {
    Window::color(red);
    ::printf("S");
    Window::color(blue);
    ::printf("T");
    Window::color(green);
    ::printf("O");
    Window::color(purple);
    ::printf("R");
    Window::color(yellow);
    ::printf("E");
    ::printf("\n");
}

void Store::upgrade(char input) {
    if(input=='1'){
        if(Map::CentreSize < MaxCentreSize && Map::money >= enlargeCentre){
            //Map::isUpgrade = true;
            Map::CentreSize ++;
            Map::money -= enlargeCentre;
        }
    }
    if(input == '2'){
        if(Map::AMineralSize < MaxAMineralSize && Map::money >= enlargeAMineral){
            //Map::isUpgrade = true;
            Map::AMineralSize++;
            Map::money -= enlargeAMineral;
        }
    }
    if(input=='3'){
        if(Map::BMineralSize < MaxBMineralSize && Map::money >= enlargeBMineral){
            //Map::isUpgrade = true;
            Map::BMineralSize++;
            Map::money -= enlargeBMineral;
        }
    }
    if(input=='4'){
        if(Map::H < MaxH-5 && Map::W < MaxW-5 && Map::money >= enlargeMap){
            //Map::isUpgrade = true;
            Map::H +=5;
            Map::W +=5;
            //this->map->sizeMap();
            Map::money -= enlargeMap;
        }
    }else if(input=='5'){
        if(Map::money >= increaseAMineralValue){
            Mineral::AMineralValue++;
            Map::money -= increaseAMineralValue;
        }

    }else if(input=='6' ){
        if(Map::money >= increaseBMineralValue){
            Mineral::BMineralValue++;
            Map::money -= increaseBMineralValue;
        }

    }
}


