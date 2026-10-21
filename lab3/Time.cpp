#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Конструктор: часы, минуты, секунды
Time::Time(int hours, int minutes, int seconds) : totalSeconds(0){
    setTime(hours, minutes, seconds);
}

// Конструктор: минуты, секунды
Time::Time(int minutes, int seconds) : totalSeconds(0){
    setTime(0, minutes, seconds);
}

// Конструктор: секунды
Time::Time(int seconds) : totalSeconds(0){
    setTime(0, 0, seconds);
}

// Получение часов
int Time::getHours() const{
    return totalSeconds / 3600;
}

// Получение минут
int Time::getMinutes() const{
    return (totalSeconds % 3600) / 60;
}

// Получение секунд
int Time::getSeconds() const{
    return totalSeconds % 60;
}

// Изменение времени
void Time::setTime(int hours, int minutes, int seconds){
    int total = hours * 3600 + minutes * 60 + seconds;
    totalSeconds = ((total % 86400) + 86400) % 86400;
}

// Вывод времени
void Time::print() const{
    cout << setfill('0')
         << setw(2) << getHours() << ":"
         << setw(2) << getMinutes() << ":"
         << setw(2) << getSeconds() << endl;
}

Time &Time::operator++(){
    setTime(0, 0, totalSeconds + 1);
    return *this;
}

Time Time::operator++(int){
    Time old = *this;
    ++(*this);
    return old;
}

Time &Time::operator--(){
    setTime(0, 0, totalSeconds - 1);
    return *this;
}

Time Time::operator--(int){
    Time old = *this;
    --(*this);
    return old;
}

Time &Time::operator+=(const Time &other){
    setTime(0, 0, totalSeconds + other.totalSeconds);
    return *this;
}

Time &Time::operator-=(const Time &other){
    setTime(0, 0, totalSeconds - other.totalSeconds);
    return *this;
}

Time &Time::operator*=(int number){
    setTime(0, 0, totalSeconds * number);
    return *this;
}

Time &Time::operator/=(int number){
    if (number > 0){
        setTime(0, 0, totalSeconds / number);
    }
    return *this;
}

Time Time::operator+(const Time& other) const {
    Time result = *this;
    result += other;
    return result;
}

Time Time::operator-(const Time& other) const {
    Time result = *this;
    result -= other;
    return result;
}

Time Time::operator*(int number) const {
    Time result = *this;
    result *= number;
    return result;
}

Time Time::operator/(int number) const {
    Time result = *this;
    result /= number;
    return result;
}

bool Time::operator<(const Time& other) const {
    return totalSeconds < other.totalSeconds;
}

bool Time::operator>(const Time& other) const {
    return totalSeconds > other.totalSeconds;
}

bool Time::operator<=(const Time& other) const {
    return totalSeconds <= other.totalSeconds;
}

bool Time::operator>=(const Time& other) const {
    return totalSeconds >= other.totalSeconds;
}

bool Time::operator==(const Time& other) const {
    return totalSeconds == other.totalSeconds;
}

bool Time::operator!=(const Time& other) const {
    return totalSeconds != other.totalSeconds;
}
