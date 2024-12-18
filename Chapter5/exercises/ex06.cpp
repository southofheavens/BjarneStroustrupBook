/*
 * Напишите программу, преобразовывающую температуру в градусах Цельсия в температуру в градусах 
 * Фаренгейта и обратно (по формуле из раздела 4.3.3). Воспользуйтесь оценками (раздел 5.8) для того,
 * чтобы убедиться в правдоподобности результатов.
 * 
 * How to compile:
 * clang++ -std=c++14 ex06.cpp
 */

#include <iostream>

int main()
{
    double c;
    std::cin >> c;
    double f = 9.0 / 5 * c + 32;
    std::cout << f << '\n';
    f = (f - 32) / (9.0 / 5); // Это уже не фаренгейты...
    std::cout << f << '\n';
    return 0; 
}
