#include <iostream>

#include "Event.h"
#include "Time.h"
using namespace std;

int main()
{
    // Конструкторы
    cout << "=== Конструкторы Time ===" << endl;

    Time t1(10, 30, 45);
    Time t2(20, 15);
    Time t3(3600);

    cout << "t1: ";
    t1.print();
    cout << endl;
    cout << "t2: ";
    t2.print();
    cout << endl;
    cout << "t3: ";
    t3.print();
    cout << endl;

    // Унарные операторы
    cout << "\n=== Унарные операторы ===" << endl;

    cout << "++t1: ";
    (++t1).print();
    cout << endl;
    cout << "t1++: ";
    (t1++).print();
    cout << endl;
    cout << "t1 после ++: ";
    t1.print();
    cout << endl;

    cout << "--t1: ";
    (--t1).print();
    cout << endl;
    cout << "t1--: ";
    (t1--).print();
    cout << endl;
    cout << "t1 после --: ";
    t1.print();
    cout << endl;

    // Арифметическое присваивание
    cout << "\n=== Арифметическое присваивание ===" << endl;

    t1 += t2;
    cout << "t1 += t2: ";
    t1.print();
    cout << endl;

    t1 -= t2;
    cout << "t1 -= t2: ";
    t1.print();
    cout << endl;

    t1 *= 2;
    cout << "t1 *= 2: ";
    t1.print();
    cout << endl;

    t1 /= 2;
    cout << "t1 /= 2: ";
    t1.print();
    cout << endl;

    // Бинарные операции
    cout << "\n=== Бинарные операции ===" << endl;

    cout << "t1 + t2: ";
    (t1 + t2).print();
    cout << endl;
    cout << "t1 - t2: ";
    (t1 - t2).print();
    cout << endl;
    cout << "t2 * 2: ";
    (t2 * 2).print();
    cout << endl;
    cout << "t1 / 2: ";
    (t1 / 2).print();
    cout << endl;

    // Сравнения
    cout << "\n=== Сравнения ===" << endl;

    cout << boolalpha;
    cout << "t1 < t2: " << (t1 < t2) << endl;
    cout << "t1 > t2: " << (t1 > t2) << endl;
    cout << "t1 <= t3: " << (t1 <= t3) << endl;
    cout << "t1 >= t3: " << (t1 >= t3) << endl;
    cout << "t1 == t3: " << (t1 == t3) << endl;
    cout << "t1 != t2: " << (t1 != t2) << endl;

    // explicit
    cout << "\n=== explicit ===" << endl;

    // Time invalid = 3600; // Ошибка: неявное преобразование запрещено
    t3.setTime(0, 0, 3600);

    cout << "t3 создан конструктором explicit: ";
    t3.print();
    cout << endl;

    // Event, mutable, static
    cout << "\n=== Расписание ===" << endl;

    Event event1;
    Event event2("Завтрак", Time(8, 0, 0));
    const Event event3("Лекция", Time(10, 0, 0), Time(11, 30, 0));

    event1.print();
    event2.print();
    event3.print();

    cout << "\nОтмечаем лекцию выполненной:" << endl;
    event3.toggleCompleted();
    event3.print();

    cout << "\nКоличество событий: " << Event::getEventCount() << endl;

    // Деструктор
    cout << "\n=== Деструктор ===" << endl;
    {
        Event temporary("Тренировка", Time(17, 0, 0), Time(18, 0, 0));

        temporary.print();

        cout << "После создания: " << Event::getEventCount() << endl;
    }

    cout << "После уничтожения: " << Event::getEventCount() << endl;

    // Event, mutable, static
    cout << "\n=== Расписание ===" << endl;
    event1.print();
    event2.print();
    event3.print();
    return 0;
}