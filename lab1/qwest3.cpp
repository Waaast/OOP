/**
 * @file qwest3.cpp
 * @brief Третье задание лабораторной работы №1
 * @details Программа реализует безопасный динамический массив, проверку индексов и изменение размера массива.
 */
#include <iostream>
/**
 * @struct SafeArray
 * @brief Хранит динамический массив и количество его элементов
 */
struct SafeArray
{
    int* data; ///< Указатель на динамический массив.
    int size;  ///< Количество элементов массива.
};
/**
 * @brief Создаёт безопасный динамический массив
 * @details Функция выделяет память для указанного количества элементов и сохраняет адрес и размер в структуре SafeArray
 * @param size Размер создаваемого массива
 * @return Структура SafeArray с созданным динамическим массивом
 */
SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
}
/**
 * @brief Возвращает ссылку на элемент массива
 * @details Функция проверяет индекс. Если индекс некорректен, выводится сообщение об ошибке и возвращается ссылка на статическую переменную-заглушку
 * @param arr Ссылка на структуру SafeArray
 * @param index Индекс требуемого элемента
 * @return Ссылка на элемент массива или на переменную-заглушку
 */
int& getElement(SafeArray& arr, int index)
{
    if (index < 0 || index >= arr.size)
    {
        std::cout << "Ошибка: индекс вне массива\n";
        static int s{};
        return s;
    }
    return arr.data[index];
}
/**
 * @brief Выводит элементы безопасного массива
 * @details Функция последовательно выводит элементы через пробел, не изменяя структуру и её данные
 * @param arr Константная ссылка на структуру SafeArray
 */
void printSafe(const SafeArray& arr)
{
    for (int index{}; index < arr.size; index++)
    {
        std::cout << arr.data[index] << ' ';
    }
    std::cout << '\n';
}
/**
 * @brief Изменяет размер динамического массива
 * @details Функция создаёт новый массив размера M и копирует сохраняемые элементы. При уменьшении размера удаляемые элементы выводятся на экран 
 * При увеличении новые элементы равны нулю. Старая динамическая память освобождается
 * @param arr Ссылка на изменяемую структуру SafeArray
 * @param M Новый размер массива
 */
void reSizeArray(SafeArray& arr, int M)
{
    int N{arr.size};
    if (M < 0)
    {
        std::cout << "Ошибка: размер не может быть отрицательным\n";
        return;
    }
    int* newD{new int[M]{}};
    int Copiryemie{};
    if (M < N)
    {
        std::cout << "Удалённые элементы:\n";
        for (int index{M}; index < N; index++)
        {
            std::cout << arr.data[index] << ' ';
        }
        std::cout << '\n';
        Copiryemie = M;
    }
    else
    {
        Copiryemie = N;
    }
    for (int index{}; index < Copiryemie; index++)
    {
        newD[index] = arr.data[index];
    }
    delete[] arr.data;
    arr.data = newD;
    arr.size = M;
}
/**
 * @brief Выполняет третье задание лабораторной работы
 * @details Функция создаёт SafeArray, заполняет и выводит его, демонстрирует безопасный доступ к элементу, изменяет размер массива и освобождает динамическую память
 * @return Код завершения: 0 при успехе, 1 при неправильном размере
 */
int main()
{
    int size{};
    std::cout << "Введите размер массива:\n";
    std::cin >> size;
    if (size <= 0)
    {
        std::cout << "Ошибка: размер должен быть больше нуля\n";
        return 1;
    }
    SafeArray arr{createArray(size)};
    std::cout << "Введите элементы массива:\n";
    for (int index{}; index < arr.size; index++)
    {
        std::cin >> arr.data[index];
    }
    std::cout << "Исходный массив:\n";
    printSafe(arr);
    getElement(arr, 2) = 999;
    std::cout << "После изменения третьего элемента:\n";
    printSafe(arr);
    int M{};
    std::cout << "Введите новый размер массива:\n";
    std::cin >> M;
    reSizeArray(arr, M);
    std::cout << "После изменения размера:\n";
    printSafe(arr);
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    return 0;
}