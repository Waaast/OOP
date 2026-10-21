#ifndef TIME_H
#define TIME_H

class Time
{
private:
    int totalSeconds;

public:
    Time(int hours, int minutes, int seconds);
    Time(int minutes, int seconds);
    explicit Time(int seconds);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void setTime(int hours, int minutes, int seconds);
    void print() const;

    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    Time& operator*=(int number);
    Time& operator/=(int number);
};

#endif