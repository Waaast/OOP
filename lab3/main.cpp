#include <iostream>
#include "Time.h"
using namespace std;

int main() {
    Time t(12, 30, 45);

    cout << "Начальное время: ";
    t.print();

    cout << "Префикс ++t: ";
    (++t).print();

    cout << "Постфикс t++: ";
    (t++).print();

    cout << "После t++: ";
    t.print();

    cout << "Префикс --t: ";
    (--t).print();

    cout << "Постфикс t--: ";
    (t--).print();

    cout << "После t--: ";
    t.print();

    return 0;
}