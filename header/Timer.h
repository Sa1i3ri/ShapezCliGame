//
// Created by 14832 on 2023/12/5.
//

#ifndef REALGAME_TIMER_H
#define REALGAME_TIMER_H
#include "Map.h"
#include "Window.h"


class Timer {
private:
    void(*func)(Window*, Map*);
    int interval;
    int cur_time;
public:
    void addFunc(void(*f)(Window *, Map *));
    void setInterval(int interval);
    void execute(Window *window, Map *map);
    Timer(int interval,void(*f)(Window*, Map*));
    Timer();

};


#endif //REALGAME_TIMER_H
