#include "movie.h"
#include <iostream>

int Movie::objectCount = 0;

// Дата по умолчанию
ReleaseDate::ReleaseDate()
    : day(1), month(1), year(2026)
{
}
// Дата с заданными значениями
ReleaseDate::ReleaseDate(int day, int month, int year)
    : day(day), month(month), year(year)
{
    if (!isValid())
    {
        this->day = 1;
        this->month = 1;
        this->year = 2026;
    }
}
// Проверка даты
bool ReleaseDate::isValid() const
{
    if (year <= 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }
    // Февраль
    if (month == 2)
    {
        if (day > 28)
        {
            return false;
        }
    }
    // Месяцы, в которых 30 дней
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            return false;
        }
    }
    // Остальные месяцы
    if (day > 31)
    {
        return false;
    }
    return true;
}
// Фильм по умолчанию
Movie::Movie()
    : title("Без названия"), duration(0), rating(0.0), releaseDate()
{
    objectCount++;
}

// Фильм с названием и продолжительностью
Movie::Movie(string title, int duration)
    : title(title), duration(duration), rating(0.0), releaseDate()
{

    if (this->title.empty())
    {
        this->title = "Без названия";
    }
    if (this->duration < 0)
    {
        this->duration = 0;
    }
    objectCount++;
}

// Фильм со всеми заданными значениями
Movie::Movie(string title, int duration, double rating, ReleaseDate releaseDate)
    : title(title), duration(duration), rating(rating), releaseDate(releaseDate)
{

    if (this->title.empty())
    {
        this->title = "Без названия";
    }
    if (this->duration < 0)
    {
        this->duration = 0;
    }
    if (this->rating < 0 || this->rating > 10)
    {
        this->rating = 0.0;
    }
    objectCount++;
}

// Получение названия
string Movie::getTitle() const
{
    return title;
}
// Получение продолжительности
int Movie::getDuration() const
{
    return duration;
}
// Получение рейтинга
double Movie::getRating() const
{
    return rating;
}
// Получение даты выхода
ReleaseDate Movie::getReleaseDate() const
{
    return releaseDate;
}

// Изменение названия
bool Movie::changeTitle(string newTitle)
{
    if (newTitle.empty())
    {
        return false;
    }
    title = newTitle;
    return true;
}
// Изменение рейтинга
bool Movie::changeRating(double newRating)
{
    if (newRating < 0 || newRating > 10)
    {
        return false;
    }
    rating = newRating;
    return true;
}
// Изменение продолжительности
bool Movie::changeDuration(int newDuration)
{
    if (newDuration <= 0)
    {
        return false;
    }
    duration = newDuration;
    return true;
}
// Изменение даты выхода
void Movie::changeReleaseDate(ReleaseDate newDate)
{
    releaseDate = newDate;
}

void ReleaseDate::print() const
{
    cout << day << "." << month << "." << year;
}
void Movie::print() const
{
    cout << "Название: " << title << endl;
    cout << "Продолжительность: " << duration << " мин." << endl;
    cout << "Рейтинг: " << rating << endl;
    cout << "Дата выхода: ";
    releaseDate.print();
    cout << endl;
}

// Деструктор
Movie::~Movie()
{
    objectCount--;
}

// Получение количества существующих фильмов
int Movie::getObjectCount()
{
    return objectCount;
}