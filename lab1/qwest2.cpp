#include <iostream>

void fillArray(int* numbers, int size)
{
    std::cout << "Введите элементы массива:\n";
    for (int index{}; index < size; index++)
    {
        std::cin >> numbers[index];
    }
}

void printArray(const int* numbers, int size)
{
    for (int index{}; index < size; index++)
    {
        std::cout << numbers[index] << ' ';
    }
    std::cout << '\n';
}

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
    std::cout << *numbers << '\n';
    return 0;
}