#include <iostream>

int** allocateMatrix(int rows, int cols)
{
    int** matrix{new int*[rows]{}};
    for (int row{}; row < rows; row++)
    {
        matrix[row] = new int[cols]{};
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows)
{
    for (int row{}; row < rows; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
}

int main()
{
    int rows{};
    int cols{};
    std::cout << "Введите количество студентов:\n";
    std::cin >> rows;
    std::cout << "Введите количество оценок:\n";
    std::cin >> cols;
    if (rows <= 0 || cols <= 0)
    {
        std::cout << "Ошибка: размеры должны быть больше нуля\n";
        return 1;
    }
    int** matrix{allocateMatrix(rows, cols)};
    freeMatrix(matrix, rows);
    matrix = nullptr;
    return 0;
}