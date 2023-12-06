//
// Created by 14832 on 2023/12/5.
//

#include "../header/Timer.h"

void Timer::setInterval(int interval) {
    this->interval = interval;
}

void Timer::addFunc(void (*f)(Window *, Map *)) {
    this->func = f;
}

void Timer::execute(Window *window, Map *map) {
    this->cur_time ++;
    if(this->cur_time == this->interval){
        this->cur_time=0;
        this->func(window,map);
    }
}

Timer::Timer(int interval, void (*f)(Window *, Map *)) {
    this->interval = interval;
    this->func  = f;
    this->cur_time =0;

}

Timer::Timer() {
    this->cur_time =0;
}
