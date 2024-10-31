/*
 * Перепишите программу из предыдущей врезки "Попробуйте", выводящую символы и соответствующие им 
 * целочисленные значения, с помощью инструкции for. Затем модифицируйте программу так, чтобы таблица
 * содержала значения для прописных символов и цифр.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis4.cpp
 */

#include <iostream>

int main()
{
    char c = 'a';
    for (int i = 0; i < 26; ++i)
    {
        std::cout << c << '\t' << static_cast<int>(c) << '\n';
        c++;
    }
    c = 'A';
    for (int i = 0; i < 26; ++i)
    {
        std::cout << c << '\t' << static_cast<int>(c) << '\n';
        c++;
    }
    c = '0';
    for (int i = 0; i < 10; ++i)
    {
        std::cout << c << '\t' << static_cast<int>(c) << '\n';
        c++;
    }
    return 0;
}
