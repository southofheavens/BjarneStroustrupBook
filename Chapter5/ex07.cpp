/*
    Квадратное уравнение имеет вид a * x^2 + b * x + c = 0. Для его решения используется формула

    x = (-b +- sqrt(b^2 - 4 * a * c)) / (2 * a).

    Тем не менее есть одна проблема: если b^2 - 4 * a * c меньше нуля, возникнет ошибка. Напишите 
    программу, вычисляющую решение квадратного уравнения. Создайте функцию, которая выводит на печать 
    все корни квадратного уравнения при заданных коэффициентах a, b и c. Когда программа обнаруживает,
    что у уравнения нет действительных корней, она должна выводить соответствующее сообщение. Как
    распознать правдоподобность результатов? Можете ли вы проверить, что они являются правильными?
*/

#include <iostream>
#include <cmath>

void Solution(int a, int b, int c)
{
    try
    {
        int discriminant = b * b - 4 * a * c;
        if (discriminant < 0) 
        {
            throw std::invalid_argument("Корней нет!"); 
        }
        else if (discriminant == 0)
        {
            std::cout << (-b / (double)(2 * a)) << '\n';
        }
        else
        {
            std::cout << ((double)(-b + sqrt(discriminant)) / (2 * a)) << ' ';
            std::cout << ((double)(-b - sqrt(discriminant)) / (2 * a)) << '\n';
        }
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
        exit(1);
    }
}

int main()
{
    std::cout << "Введите коэффициенты a, b и c квадратного уравнения: ";
    int a, b, c;
    std::cin >> a >> b >> c;
    Solution(a, b, c);
    return 0;
}