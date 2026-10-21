#include "Event.h"
#include <iostream>
using namespace std;

int Event::eventCount = 0;

Event::Event()
    : name("Без названия"), startTime(0), endTime(0), completed(false) {
    eventCount++;
}

Event::Event(string name, Time start)
    : name(name), startTime(start), endTime(start), completed(false) {
    eventCount++;
}

Event::Event(string name, Time start, Time end)
    : name(name), startTime(start), endTime(end), completed(false) {
    eventCount++;
}

Event::~Event() {
    eventCount--;
}

void Event::print() const {
    cout << (completed ? "[✓] " : "[✗] ");

    startTime.print();
    cout << " - ";
    endTime.print();

    cout << " | " << name << endl;
}

void Event::toggleCompleted() const {
    completed = !completed;
}

int Event::getEventCount() {
    return eventCount;
}