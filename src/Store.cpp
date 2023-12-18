//
// Created by 14832 on 2023/12/18.
//

#include "../header/Store.h"

Store::Store(Map *map) {
    this->map = map;
}

void Store::display() {
    system("cls");

    displayTitle();

    Window::color(white);
    printf("Press 1 to enlarge Centre\n");

    Window::color(red);
    printf("Press 2 to enlarge AMineral\n");

    Window::color(blue);
    printf("Press 3 to enlarge BMineral\n");

    Window::color(yellow);
    printf("Press 4 to enlarge Map\n");

    Window::color(red);
    printf("Press 4 to increase AMineral value\n");

    Window::color(blue);
    printf("Press 4 to increase BMineral value\n");

    Window::color(white);
    ::printf("Money : %d",map->overallValue);


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

    }
}


