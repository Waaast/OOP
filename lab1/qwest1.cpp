/**
 * @file qwest1.cpp
 * @brief Первое задание лабораторной работы №1.
 * @details работа со статическим массивом, ссылками и циклом range-based for.
 */
#include <iostream>
/**
 * @brief Заполняет массив числами, введёнными пользователем
 * @details Функция последовательно считывает 10 целых чисел и записывает их в элементы исходного массива
 * @param numbers Ссылка на статический массив из 10 целых чисел
 */
void fillArray(int (&numbers)[10])
{
    std::cout << "Введите 10 целых чисел:\n";
    for (int& x : numbers)
    {
        std::cin >> x;
    }
}
/**
 * @brief Выводит элементы массива на экран
 * @details Функция перебирает элементы массива с помощью range-based for и выводит их и пробел
 * @param numbers Константная ссылка на массив из 10 целых чисел
 */
void printArray(const int (&numbers)[10])
{
    for (auto x : numbers)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
/**
 * @brief Меняет местами два элемента массива
 * @details Для сохранения первого элемента используется временная переменная
 * @param numbers Ссылка на статический массив из 10 целых чисел
 * @param firstIndex Индекс первого элемента
 * @param secondIndex Индекс второго элемента
 */
void swapElements(
    int (&numbers)[10],
    const int& firstIndex,
    const int& secondIndex)
{
    int a = numbers[firstIndex];
    numbers[firstIndex] = numbers[secondIndex];
    numbers[secondIndex] = a;
}
/**
 * @brief Умножает каждый элемент массива на два
 * @details Функция использует неконстантную ссылку на каждый элемент, поэтому изменяет значения в исходном массиве
 * @param numbers Ссылка на статический массив из 10 целых чисел
 */
void multiplyByTwo(int (&numbers)[10])
{
    for (int& x : numbers)
    {
        x = x * 2;
    }
}
/**
 * @brief Выполняет первое задание
 * @details Функция заполняет массив, выводит его, запрашивает номера двух элементов, меняет их местами и умножает все элементы на два.
 * @return Код завершения: 0 при успехе, 1 при недопустимых номерах элементов
 */
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
    if (firstPos < 1 || firstPos > 10 ||
        secondPos < 1 || secondPos > 10)
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