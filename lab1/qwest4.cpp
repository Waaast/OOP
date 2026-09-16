/**
 * @file qwest4.cpp
 * @brief Четвёртое задание лабораторной работы №1
 * @details Программа создаёт двумерный динамический массив для хранения оценок студентов, заполняет его, выводит его, и освобождает память.
 */
#include <iostream>
#include <string>
/**
 * @brief Выделяет память для двумерного динамического массива
 * @details Сначала создаётся массив указателей на массивы, после чего для каждой строки создаётся отдельный динамический массив
 * @param rows Количество строк массива
 * @param cols Количество столбцов массива
 * @return Указатель на созданный двумерный массив
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix{new int*[rows]{}};
    for (int row{}; row < rows; row++)
    {
        matrix[row] = new int[cols]{};
    }
    return matrix;
}
/**
 * @brief Освобождает память, занятую двумерным массивом
 * @details Сначала освобождается память каждого массива, после чего освобождается массив указателей на массивы
 * @param matrix Указатель на двумерный динамический массив
 * @param rows Количество строк массива
 */
void freeMatrix(int** matrix, int rows)
{
    for (int row{}; row < rows; row++)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
}
/**
 * @brief Заполняет двумерный массив оценками.
 * @details Функция последовательно запрашивает у пользователя оценку для каждого студента и записывает её в соответствующий элемент массива.
 * @param matrix Указатель на двумерный динамический массив.
 * @param rows Количество студентов (строк массива)
 * @param cols Количество оценок (столбцов массива)
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    std::cout << "Введите оценки студентов:\n";
    for (int row{}; row < rows; row++)
    {
        for (int col{}; col < cols; col++)
        {
            std::cout << "Студент " << row + 1 << ", оценка " << col + 1 << ": ";
            std::cin >> matrix[row][col];
        }
    }
}
/**
 * @brief Выводит двумерный массив на экран
 * @details Функция выводит заголовок и элементы массива. Если параметр showBorders равен true, вокруг элементов выводится рамка из *
 * @param matrix Указатель на двумерный динамический массив
 * @param rows Количество строк массива
 * @param cols Количество столбцов массива
 * @param showBorders Определяет, нужно ли выводить рамку
 * @param title Заголовок, выводимый перед массивом
 */
void printMatrix(
    int** matrix,
    int rows, int cols,
    bool showBorders = true,
    std::string title = "Matrix")
{
    std::cout << title << '\n';
    if (showBorders)
    {
        for (int symbol{}; symbol < cols * 4 + 1; symbol++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
        for (int row{}; row < rows; row++)
        {
            std::cout << '*';
            for (int col{}; col < cols; col++)
            {
                std::cout << ' ' << matrix[row][col] << " *";
            }
            std::cout << '\n';
            for (int symbol{}; symbol < cols * 4 + 1; symbol++)
            {
                std::cout << '*';
            }
            std::cout << '\n';
        }
}
    else
    {
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                std::cout << matrix[row][col] << ' ';
            }
            std::cout << '\n';
        }
    }
}
/**
 * @brief Выполняет четвёртое задание лабораторной работы.
 * @details Функция запрашивает размеры массива, выделяет память,
 * заполняет массив оценками и выводит три варианта его вывода. После завершения работы динамическая память очищается
 * @return Код завершения: 0 при успехе, 1 при неправильных размерах
 */
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
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols, true, std::string("\nОценки")); 
    freeMatrix(matrix, rows);
    matrix = nullptr;
    return 0;
}