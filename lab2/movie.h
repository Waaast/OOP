/**
 * @file movie.h
 * @brief Объявление классов ReleaseDate и Movie.
 */

#ifndef MOVIE_H
#define MOVIE_H
#include <string>

using namespace std;
/**
 * @class ReleaseDate
 * @brief Класс для хранения даты выхода фильма.
 *
 * Хранит день, месяц и год выхода фильма и обеспечивает
 * проверку корректности даты.
 */
class ReleaseDate
{
private:
    int day;   ///< День выхода фильма
    int month; ///< Месяц выхода фильма
    int year;  ///< Год выхода фильма
    /**
     * @brief Проверяет корректность даты.
     * @return true, если дата корректна, иначе false
     */
    bool isValid() const;

public:
    /**
     * @brief Создает дату по умолчанию.
     */
    ReleaseDate();
    /**
     * @brief Создает дату с заданными значениями.
     * @param day День
     * @param month Месяц
     * @param year Год
     */
    ReleaseDate(int day, int month, int year);
    /**
     * @brief Выводит дату выхода фильма.
     */
    void print() const;
};
/**
 * @class Movie
 * @brief Класс для хранения информации о фильме.
 * Хранит название, продолжительность, рейтинг и дату выхода фильма.
 * Позволяет изменять данные фильма и получать информацию о нем.
 */
class Movie
{
private:
    string title;            ///< Название фильма
    int duration;            ///< Продолжительность фильма в минутах
    double rating;           ///< Рейтинг фильма
    ReleaseDate releaseDate; ///< Дата выхода фильма

    static int objectCount;  ///< Количество существующих объектов Movie

public:
    /**
     * @brief Создает фильм со значениями по умолчанию.
     */
    Movie();
    /**
     * @brief Создает фильм с названием и продолжительностью.
     * @param title Название фильма
     * @param duration Продолжительность фильма в минутах
     */
    Movie(string title, int duration);
    /**
     * @brief Создает фильм с заданными значениями.
     * @param title Название фильма
     * @param duration Продолжительность фильма в минутах
     * @param rating Рейтинг фильма
     * @param releaseDate Дата выхода фильма
     */
    Movie(string title, int duration, double rating, ReleaseDate releaseDate);
    /**
     * @brief Уничтожает объект Movie.
     */
    ~Movie();
    /**
     * @brief Возвращает количество существующих объектов Movie.
     * @return Количество существующих объектов
     */
    static int getObjectCount();
    /**
     * @brief Возвращает название фильма.
     * @return Название фильма
     */
    string getTitle() const;
    /**
     * @brief Возвращает продолжительность фильма.
     * @return Продолжительность фильма в минутах
     */
    int getDuration() const;
    /**
     * @brief Возвращает рейтинг фильма.
     * @return Рейтинг фильма
     */
    double getRating() const;
    /**
     * @brief Возвращает дату выхода фильма.
     * @return Дата выхода фильма
     */
    ReleaseDate getReleaseDate() const;
    /**
     * @brief Изменяет название фильма.
     * @param newTitle Новое название фильма
     * @return true, если название изменено, иначе false
     */
    bool changeTitle(string newTitle);
    /**
     * @brief Изменяет рейтинг фильма.
     * @param newRating Новый рейтинг фильма
     * @return true, если рейтинг изменен, иначе false
     */
    bool changeRating(double newRating);
    /**
     * @brief Изменяет продолжительность фильма.
     * @param newDuration Новая продолжительность фильма в минутах
     * @return true, если продолжительность изменена, иначе false
     */
    bool changeDuration(int newDuration);
    /**
     * @brief Изменяет дату выхода фильма.
     * @param newDate Новая дата выхода фильма
     */
    void changeReleaseDate(ReleaseDate newDate);
    /**
     * @brief Выводит информацию о фильме.
     */
    void print() const;
};

#endif