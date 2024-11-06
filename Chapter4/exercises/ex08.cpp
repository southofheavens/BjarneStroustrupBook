/*
 * Легенда гласит, что некий царь захотел поблагодарить изобретателя шахмат и предложил ему попросить
 * любую награду. Изобретатель попросил положить на первую клетку одно зерно риса, на вторую - два,
 * на третью - четыре и так далее, удваивая количество зерен на каждой из 64 клеток. На первый
 * взгляд, это желание выглядит вполне скромным, но на самом деле в царстве не было такого количества
 * риса! Напишите программу, вычисляющую, сколько клеток надо заполнить, чтобы изобретатель получил
 * не менее 1000 зерен риса, не менее 1 000 000 зерен риса и не менее 1 000 000 000 зерен риса. Вам,
 * разумеется, понадобится цикл и, вероятно, несколько переменных типа int, для того, чтобы отслеживать
 * текущий номер клетки, количество зерен в текущей клетке и количество зерен во всех предыдущих 
 * клетках. Мы предлагаем на каждой итерации цикла выводить на экран значения всех этих переменных,
 * чтобы видеть промежуточные результаты.
 * 
 * How to compile:
 * clang++ -std=c++14 ex08.cpp
 */

#include <iostream>

int main()
{
    int countOfGrains = 1;
    int numOfFirstCell = 0;
    int numOfSecondCell = 0;
    int numOfThirdCell = 0;

    int totalRice = 0;

    int numOfCell = 1;
    while (numOfThirdCell == 0)
    {
        totalRice += countOfGrains;
        std::cout << countOfGrains << '\n';
        if (numOfFirstCell == 0 && totalRice >= 1000)
        {
            numOfFirstCell = numOfCell;
        }
        else if (numOfSecondCell == 0 && totalRice >= 1000000)
        {
            numOfSecondCell = numOfCell;
        }
        else if (numOfThirdCell == 0 && totalRice >= 1000000000)
        {
            numOfThirdCell = numOfCell;
        }
        countOfGrains *= 2;
        numOfCell++;
    }
    std::cout << numOfFirstCell << ' ' << numOfSecondCell << ' ' << numOfThirdCell << '\n';
    return 0;
}
