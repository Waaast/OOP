#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;
// Дата выхода фильма
class ReleaseDate {
private:
    int day;
    int month;
    int year;
public:
};

// Фильм
class Movie {
private:
    string title;
    int duration;
    double rating;
    ReleaseDate releaseDate;
public:
};

#endif