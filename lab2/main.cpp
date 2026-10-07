#include "movie.h"
#include <iostream>

using namespace std;

int main()
{
    Movie movie1;

    Movie movie2("Интерстеллар", 169);

    ReleaseDate date3(18, 5, 2001);
    Movie movie3("Шрек", 90, 8.0, date3);

    cout << "Фильм 1:" << endl;
    movie1.print();

    cout << "\nФильм 2:" << endl;
    movie2.print();

    cout << "\nФильм 3:" << endl;
    movie3.print();

    cout << "\nИзменение фильма 1:" << endl;
    movie1.changeTitle("Начало");
    movie1.changeDuration(148);
    movie1.changeRating(8.8);
    movie1.changeReleaseDate(ReleaseDate(16, 7, 2010));
    movie1.print();

    cout << "\nПопытка некорректных изменений:" << endl;
    if (!movie1.changeRating(15))
    {
        cout << "Некорректный рейтинг не установлен" << endl;
    }
    if (!movie1.changeDuration(-100))
    {
        cout << "Некорректная продолжительность не установлена" << endl;
    }
    cout << "Фильм 1:" << endl;
    movie1.print();

    cout << "\nПроверка независимости объектов:" << endl;
    movie2.changeRating(9.0);
    cout << "Фильм 2 после изменения:" << endl;
    movie2.print();
    cout << "\nФильм 3:" << endl;
    movie3.print();

    cout << "\nКоличество объектов Movie: "
     << Movie::getObjectCount() << endl;

    cout << "\nПроверка счетчика объектов:" << endl;
    cout << "Сейчас объектов: " << Movie::getObjectCount() << endl;
    {
    Movie temporaryMovie;
    cout << "\nВременный фильм:" << endl;
    temporaryMovie.print();
    cout << "После создания временного объекта: "
         << Movie::getObjectCount() << endl;
    }
    cout << "После уничтожения временного объекта: " << Movie::getObjectCount() << endl;

    return 0;
}