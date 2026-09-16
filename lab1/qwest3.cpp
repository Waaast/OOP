#include <iostream>

struct SafeArray
{
    int* data;
    int size;
};

SafeArray createArray(int size)
{
    SafeArray arr;
    arr.data = new int[size]{};
    arr.size = size;
    return arr;
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

void printSafe(const SafeArray& arr)
{
    for (int index{}; index < arr.size; index++)
    {
        std::cout << arr.data[index] << ' ';
    }
    std::cout << '\n';
}

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