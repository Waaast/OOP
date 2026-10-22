
#ifndef EVENT_H
#define EVENT_H

#include <string>

#include "Time.h"

/**
 * @file Event.h
 * @brief Класс для работы с мероприятиями расписания.
 */

/**
 * @class Event
 * @brief Представляет мероприятие в расписании на день.
 */
class Event
{
  private:
    std::string name; ///< Название мероприятия.
    Time startTime; ///< Время начала мероприятия.
    Time endTime; ///< Время окончания мероприятия.

    mutable bool completed; ///< Статус выполнения мероприятия.
    static int eventCount; ///< Количество существующих мероприятий.

  public:
    /**
     * @brief Создаёт мероприятие со значениями по умолчанию.
     */
    Event();
    /**
     * @brief Создаёт мероприятие с названием и временем начала.
     * @param name Название мероприятия.
     * @param start Время начала мероприятия.
     */
    Event(std::string name, Time start);
    /**
     * @brief Создаёт мероприятие с названием, временем начала и окончания.
     * @param name Название мероприятия.
     * @param start Время начала мероприятия.
     * @param end Время окончания мероприятия.
     */
    Event(std::string name, Time start, Time end);
    /**
     * @brief Уничтожает мероприятие и уменьшает счётчик объектов.
     */
    ~Event();

    /**
     * @brief Выводит информацию о мероприятии.
     */
    void print() const;
    /**
     * @brief Переключает статус выполнения мероприятия.
     */
    void toggleCompleted() const;

    /**
     * @brief Возвращает количество существующих мероприятий.
     * @return Количество объектов Event.
     */
    static int getEventCount();
};

#endif
