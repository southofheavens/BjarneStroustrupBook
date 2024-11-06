/*
 * Попробуйте вычислить количество зерен риса, запрошенных изобретателем в упр. 8. Оказывается, что
 * это число настолько велико, что для его точного представления не подходит ни тип int, ни тип 
 * double. Чему равно наибольшее количество клеток, для которых еще можно вычислить точное 
 * количество зерен риса (с использованием переменной типа int). Определите наибольшее количество
 * клеток, для которых еще можно вычислить приближенное количество зерен (с использованием
 * переменной типа double)?
 * 
 * How to compile:
 * clang++ -std=c++14 ex09.cpp
 */

constexpr int COUNT_OF_CELLS = 64;

#include <iostream>

int main()
{
    int numOfIntCells = 1;
    double numOfDoubleCells = 1;

    int integerCountOfGrains = 1;
    double doubleCountOfGrains = 1;

    int integerRiceCount = 1;
    double doubleRiceCount = 1;

    for(int i = 1; i < COUNT_OF_CELLS; ++i)
    {
        std::cout << integerRiceCount << " " << doubleRiceCount << " " << i << '\n';

        if (integerRiceCount >= 0)
        {
            integerCountOfGrains *= 2;
            integerRiceCount += integerCountOfGrains;
            if (integerRiceCount >= 0) {
                numOfIntCells++;
            }
        }

        if (doubleRiceCount >= 0)
        {
            doubleCountOfGrains *= 2;
            doubleRiceCount += doubleCountOfGrains;
            if (doubleRiceCount != INFINITY) {
                numOfDoubleCells++;
            }
        } 
    }
    std::cout << "Для типа int - " << numOfIntCells << ", для типа double - " << numOfDoubleCells << '\n';
    return 0;
}
