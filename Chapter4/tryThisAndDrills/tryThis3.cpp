/*
 * Символ 'b' равен char('a'+1), 'c' равен char('a'+2) и т.д. Используя цикл, выведите на экран таблицу
 * символов и соответующих им целочисленных значений.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis3.cpp
 */

#include <iostream>

int main()
{
    int i = 0;
    char c = 'a';
    while (i < 26)
    {
        std::cout << c << '\t' << static_cast<int>(c) << '\n';
        i++;
        c++;
    }
    return 0;
}
