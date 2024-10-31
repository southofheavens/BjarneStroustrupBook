/*
 * Реализуйте функцию square(), не используя оператор умножения; иначе говоря, выполните умножение
 * x*x с помощью повторяющегося сложения (начните с переменной, равной нулю, и x раз добавьте к ней)
 * число x). Затем выполните версию "первопрограммы", используя функцию square().  
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis5.cpp
 */

#include <iostream>

int Square(int x)
{
    int result = 0;
    for (int i = 0; i < x; ++i) {
        result += x;
    }
    return result;
}

int main()
{
    for (int i = 0; i < 100; ++i) {
        std::cout << i << '\t' << Square(i) << '\n';
    }
    return 0;
}
