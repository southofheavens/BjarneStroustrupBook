#include <iostream>
#include "rational.h"

int main()
{
    try
    {
        Rational num1;
        std::cin >> num1;
        double num1d = num1.ConvertToDouble();
        std::cout << num1 << " " << num1d << '\n';
    }
    catch (Rational::Invalid)
    {
        std::cerr << "Знаменатель не должен быть равен нулю!\n";
        exit(1);
    }
    return 0;
}
