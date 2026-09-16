#include <iostream>

struct SafeArray
{
    int* data;
    int size;
};

SafeArray createArray(int size)
{
    SafeArray array;

    array.data = new int[size]{};
    array.size = size;

    return array;
}

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

void printSafe(const SafeArray& array)
{
    for (int index{}; index < array.size; index++)
    {
        std::cout << array.data[index] << ' ';
    }
    std::cout << '\n';
}

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
    SafeArray mArray{createArray(size)};
    std::cout << "Введите элементы массива:\n";
    for (int index{}; index < mArray.size; index++)
    {
        std::cin >> mArray.data[index];
    }
    std::cout << "Исходный массив:\n";
    printSafe(mArray);
    getElement(mArray, 2) = 999;
    std::cout << "После изменения третьего элемента:\n";
    printSafe(mArray);
}