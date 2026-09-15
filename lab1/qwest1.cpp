#include <iostream>

void fillArray(int (&numbers)[10])
{
    std::cout << "Введите 10 целых чисел:\n";

    for (int& x : numbers)
    {
        std::cin >> x;
    }
}

void printArray(const int (&numbers)[10])
{
    for (auto x : numbers)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}

void swapElements(int (&numbers)[10], const int& firstIndex, const int& secondIndex)
{
    int a = numbers[firstIndex];
    numbers[firstIndex] = numbers[secondIndex];
    numbers[secondIndex] = a;
}

void multiplyByTwo(int (&numbers)[10])
{
    for (int& x : numbers)
    {
        x = x * 2; 
    }
}

int main()
{
    int numbers[10]{};
    int firstPos{};
    int secondPos{};
    fillArray(numbers);
    std::cout << "Исходный массив:\n";
    printArray(numbers);
    std::cout << "Введите номера двух элементов от 1 до 10:\n";
    std::cin >> firstPos >> secondPos;
    if (firstPos < 1 || firstPos > 10 || secondPos < 1 || secondPos > 10)
    {
        std::cout << "Ошибка: номера должны быть от 1 до 10\n";
        return 1;
    }
    swapElements(numbers, firstPos - 1, secondPos - 1);
    std::cout << "После обмена элементов:\n";
    printArray(numbers);
    multiplyByTwo(numbers);
    std::cout << "После умножения на 2:\n";
    printArray(numbers);
    return 0;
}