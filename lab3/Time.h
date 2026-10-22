
#ifndef TIME_H
#define TIME_H

/**
 * @file Time.h
 * @brief Класс для работы со временем.
 */

/**
 * @class Time
 * @brief Представляет время в пределах суток.
 */
class Time
{
  private:
    int totalSeconds; ///< Количество секунд от начала суток.

  public:
    /**
     * @brief Создаёт время из часов, минут и секунд.
     * @param hours Часы.
     * @param minutes Минуты.
     * @param seconds Секунды.
     */
    Time(int hours, int minutes, int seconds);
    /**
     * @brief Создаёт время из минут и секунд.
     * @param minutes Минуты.
     * @param seconds Секунды.
     */
    Time(int minutes, int seconds);
    /**
     * @brief Создаёт время из секунд.
     * @param seconds Секунды.
     */
    explicit Time(int seconds);

    /**
     * @brief Возвращает часы.
     * @return Количество часов.
     */
    int getHours() const;
    /**
     * @brief Возвращает минуты.
     * @return Количество минут.
     */
    int getMinutes() const;
    /**
     * @brief Возвращает секунды.
     * @return Количество секунд.
     */
    int getSeconds() const;

    /**
     * @brief Устанавливает время.
     * @param hours Часы.
     * @param minutes Минуты.
     * @param seconds Секунды.
     */
    void setTime(int hours, int minutes, int seconds);
    /**
     * @brief Выводит время в формате ЧЧ:ММ:СС.
     */
    void print() const;

    /**
     * @brief Увеличивает время на одну секунду (префикс).
     * @return Ссылка на изменённый объект.
     */
    Time &operator++();
    /**
     * @brief Увеличивает время на одну секунду (постфикс).
     * @param int Формальный параметр для отличия постфикса.
     * @return Объект до увеличения.
     */
    Time operator++(int);
    /**
     * @brief Уменьшает время на одну секунду (префикс).
     * @return Ссылка на изменённый объект.
     */
    Time &operator--();
    /**
     * @brief Уменьшает время на одну секунду (постфикс).
     * @param int Формальный параметр для отличия постфикса.
     * @return Объект до уменьшения.
     */
    Time operator--(int);

    /**
     * @brief Прибавляет другое время к текущему.
     * @param other Прибавляемое время.
     * @return Ссылка на изменённый объект.
     */
    Time &operator+=(const Time &other);
    /**
     * @brief Вычитает другое время из текущего.
     * @param other Вычитаемое время.
     * @return Ссылка на изменённый объект.
     */
    Time &operator-=(const Time &other);
    /**
     * @brief Умножает время на число.
     * @param number Множитель.
     * @return Ссылка на изменённый объект.
     */
    Time &operator*=(int number);
    /**
     * @brief Делит время на число.
     * @param number Делитель.
     * @return Ссылка на изменённый объект.
     */
    Time &operator/=(int number);

    /**
     * @brief Складывает два значения времени.
     * @param other Второе время.
     * @return Результат сложения.
     */
    Time operator+(const Time &other) const;
    /**
     * @brief Вычитает одно время из другого.
     * @param other Вычитаемое время.
     * @return Результат вычитания.
     */
    Time operator-(const Time &other) const;
    /**
     * @brief Умножает время на число.
     * @param number Множитель.
     * @return Результат умножения.
     */
    Time operator*(int number) const;
    /**
     * @brief Делит время на число.
     * @param number Делитель.
     * @return Результат деления.
     */
    Time operator/(int number) const;

    /**
     * @brief Проверяет, меньше ли текущее время другого.
     * @param other Время для сравнения.
     * @return true, если текущее время меньше.
     */
    bool operator<(const Time &other) const;
    /**
     * @brief Проверяет, больше ли текущее время другого.
     * @param other Время для сравнения.
     * @return true, если текущее время больше.
     */
    bool operator>(const Time &other) const;
    /**
     * @brief Проверяет, меньше ли текущее время или равно другому.
     * @param other Время для сравнения.
     * @return true, если текущее время меньше или равно.
     */
    bool operator<=(const Time &other) const;
    /**
     * @brief Проверяет, больше ли текущее время или равно другому.
     * @param other Время для сравнения.
     * @return true, если текущее время больше или равно.
     */
    bool operator>=(const Time &other) const;
    /**
     * @brief Проверяет равенство двух значений времени.
     * @param other Время для сравнения.
     * @return true, если значения равны.
     */
    bool operator==(const Time &other) const;
    /**
     * @brief Проверяет неравенство двух значений времени.
     * @param other Время для сравнения.
     * @return true, если значения различаются.
     */
    bool operator!=(const Time &other) const;
};

#endif
