#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;
// Дата выхода фильма
class ReleaseDate
{
private:
    int day;
    int month;
    int year;

    bool isValid() const;

public:
    ReleaseDate();
    ReleaseDate(int day, int month, int year);

    void print() const;
};
// Фильм
class Movie
{
private:
    string title;
    int duration;
    double rating;
    ReleaseDate releaseDate;

    static int objectCount;

public:
    Movie();
    Movie(string title, int duration);
    Movie(string title, int duration, double rating, ReleaseDate releaseDate);

    ~Movie();

    static int getObjectCount();

    string getTitle() const;
    int getDuration() const;
    double getRating() const;
    ReleaseDate getReleaseDate() const;

    bool changeTitle(string newTitle);
    bool changeRating(double newRating);
    bool changeDuration(int newDuration);
    void changeReleaseDate(ReleaseDate newDate);
    void print() const;
};
#endif