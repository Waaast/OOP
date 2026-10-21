#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Time.h"

class Event {
private:
    std::string name;
    Time startTime;
    Time endTime;

    mutable bool completed;
    static int eventCount;

public:
    Event();
    Event(std::string name, Time start);
    Event(std::string name, Time start, Time end);
    ~Event();

    void print() const;
    void toggleCompleted() const;

    static int getEventCount();
};

#endif