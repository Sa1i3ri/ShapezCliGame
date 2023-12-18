//
// Created by 14832 on 2023/12/13.
//

#include "../header/MainInterface.h"

MainInterface::MainInterface() {}

void MainInterface::display(Map *map) {
    system("cls");

    displayTitle();

    Window::color(white);
    printf("Press 1 to start ");
    Window::color(red);
    printf("Level 1 \t");

    Window::color(white);
    printf("Press 2 to start ");
    Window::color(blue);
    printf("Level 2 \t");

    Window::color(white);
    printf("Press 3 to start ");
    Window::color(green);
    printf("Level 3 \t");
    ::printf("\n");

    Window::color(indigo);
    printf("Press s to enter store\n");


}

void MainInterface::displayTitle() {
    Window::color(red);
    ::printf("S");
    Window::color(blue);
    ::printf("H");
    Window::color(green);
    ::printf("A");
    Window::color(purple);
    ::printf("P");
    Window::color(yellow);
    ::printf("E");
    Window::color(indigo);
    ::printf("Z");
    ::printf("\n");
}





