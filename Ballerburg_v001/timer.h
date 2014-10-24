#ifndef TIMER_H
#define TIMER_H

#include <set>

class Timer
{
public:
    Timer(int startTime) :
        currentTime(startTime),
        startTime(startTime) { timers.insert((this)); }

    ~Timer() { timers.erase(this); }

    void reset() { currentTime = startTime; }
    void stop() { currentTime = 0; }
    bool active() const { return currentTime >= 0; }
    bool expired() const { return !active(); }

    int getCurrentTime() const { return currentTime; }

    static void updateAll(int elapsedTime);

private:
    Timer(const Timer& other) = delete;
    Timer& operator=(const Timer& rhs) = delete;

    void update(int elapsedTime) {
        if (active()) { currentTime -= elapsedTime;  } }

    int currentTime;
    const int startTime;

    static std::set<Timer*> timers;
};

#endif // TIMER_H
