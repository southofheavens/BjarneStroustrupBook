/* 
 * Для того чтобы увидеть неперехваченное исключение в действии, запустите небольшую программу, в которой
 * использзуется функция error() и при этом не перехватываются никакие исключения.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis4.cpp
 */

#include <iostream>
#include <exception>

int main()
{
    int i;
    std::cin >> i;
    if (i < 0 || i == 0 || i > 0) throw std::runtime_error("");
    return 0;
}
