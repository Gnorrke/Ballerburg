#include "timer.h"


std::set<Timer*> Timer::timers;

void Timer::updateAll(int elapsedTime)
{
    for(auto iter = timers.begin(); iter != timers.end(); ++iter) {
        (*iter)->update(elapsedTime);
    }
}
