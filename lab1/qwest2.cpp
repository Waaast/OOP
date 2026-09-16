/**
 * @file qwest2.cpp
 * @brief Второе задание лабораторной работы №1.
 * @details Программа демонстрирует работу с динамическим массивом, указателями, операторами new[] и delete[].
 */
#include <iostream>
/**
 * @brief Заполняет массив числами, введёнными пользователем
 * @details Функция последовательно считывает size целых чисел и записывает их в элементы исходного массива
 * @param numbers Указатель на динамический массив целых чисел
 * @param size Размер массива
 */
void fillArray(int* numbers, int size)
{
    std::cout << "Введите элементы массива:\n";
    for (int index{}; index < size; index++)
    {
        std::cin >> numbers[index];
    }
}
/**
 * @brief Выводит массив на экран
 * @details Функция последовательно выводит элементы массива в одну строку через пробел
 * @param numbers Указатель на динамический массив целых чисел
 * @param size Размер массива
 */
void printArray(const int* numbers, int size)
{
    for (int index{}; index < size; index++)
    {
        std::cout << numbers[index] << ' ';
    }
    std::cout << '\n';
}
/**
 * @brief Удаляет первый отрицательный элемент и все элементы после него.
 * @details Функция находит первый отрицательный элемент, создаёт новый динамический массив и копирует в него элементы, 
 * расположенные до отрицательного. После этого старый массив освобождается, а исходный указатель направляется на новый массив.
 * @param[in,out] numbers Ссылка на указатель на динамический массив.
 * @param[in] size Размер исходного массива.
 */
void process(int*& numbers, int size)
{
    int otrIndex{-1};
    for (int index{}; index < size; index++)
    {
        if (numbers[index] < 0)
        {
            otrIndex = index;
            break;
        }
    }
    if (otrIndex == -1)
    {
    std::cout << "Отрицательных элементов нет, массив не изменился\n";
    return;
    }
    int* newNumbers{new int[otrIndex]{}};

    for (int index{}; index < otrIndex; index++)
    {
    newNumbers[index] = numbers[index];
    }
    delete[] numbers;
    numbers = newNumbers;
    size = otrIndex;

    std::cout << "Результат:\n";
    if (size == 0)
    {
        std::cout << "Массив пуст\n";
    }
    else
    {
        printArray(numbers, size);
    }
}
/**
 * @brief Выполняет второе задание
 * @details Функция запрашивает размер массива, создаёт динамический массив, заполняет его, выводит на экран, удаляет элементы начиная с первого отрицательного и выводит результат. В конце работы освобождает память и обнуляет указатель.
 * @return Код завершения: 0 при успехе, 1 при недопустимом размере массива
 */
int main()
{
    int size{};
    std::cout << "Введите размер массива:\n";
    std::cin >> size;
    if (size <= 0)
    {
        std::cout << "Ошибка: размер задается числом и должен быть больше нуля\n";
        return 1;
    }
    int* numbers{new int[size]{}};
    fillArray(numbers, size);
    std::cout << "Исходный массив:\n";
    printArray(numbers, size);
    process(numbers, size);
    delete[] numbers;
    numbers = nullptr;
    if (numbers != nullptr)//5 само содержимое указателя
    {
        std::cout << *numbers << '\n';
    }
    else
    {
        std::cout << "Указатель обнулён, значение вывести нельзя\n";
    }
    return 0;
}