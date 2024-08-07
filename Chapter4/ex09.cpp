/*
    Попробуйте вычислить количество зерен риса, запрошенных изобретателем в упр. 8. Оказывается, что
    это число настолько велика, что для его точного представления не подходит ни тип int, ни тип 
    double. Чему равно наибольшее количество клеток, для которых еще можно вычислить точное 
    количество зерен риса (с использованием переменной типа int). Определите наибольшее количество
    клеток, для которых еще можно вычислить приближенное количество зерен (с использованием
    переменной типа double)?
*/

constexpr int COUNT_OF_CELLS = 64;

#include <iostream>

int main()
{
    int numOfIntCells = 1;
    double numOfDoubleCells = 1;

    int integerCountOfGrains = 1;
    double doubleCountOfGrains = 1;


    for(int i = 1; i < COUNT_OF_CELLS; ++i)
    {
        if (integerCountOfGrains >= 0)
        {
            integerCountOfGrains *= 2;
            if (integerCountOfGrains >= 0)
            {
                numOfIntCells++;
            }
        }

        if (doubleCountOfGrains >= 0)
        {
            doubleCountOfGrains *= 2;
            if (doubleCountOfGrains != INFINITY)
            {
                numOfDoubleCells++;
            }
        }
        
        std::cout << integerCountOfGrains << " " << doubleCountOfGrains << '\n';
    }
    std::cout << "Для типа int - " << numOfIntCells << ", для типа double - " << numOfDoubleCells << '\n';
    return 0;
}

