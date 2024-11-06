/*
 * Выполните эту программу при разных значениях. Выведите на экран значения переменных area1, area2,
 * area3 и ratio. Вставьте в программу больше проверок разных ошибок. Вы уверены, что перехватываете
 * все возможные ошибки? Это вопрос без подвоха; в данном конкретном примере можно доказать перехват
 * всех возможных ошибок.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis3.cpp
 */

#include <iostream>

int Area(int length, int width) 
{
    return length*width;
}

int FramedArea(int length, int width)
{
    return Area(length - 2, width - 2);
}

int F(int x, int y, int z)
{
    // Аргументами функции FramedArea должны быть числа, которые >2.

    int area1 = Area(x,y);
    if (area1 <= 0)
    {
        std::cout << "Неположительная площадь\n";
        exit(1);
    }
    int area2 = FramedArea(1,z);    // значение area2 всегда будет меньше нуля (при положительном z)
                                    // при отрицательном z значение area2 будет положительным, но 
                                    // как площадь может получиться положительной при отрицательных
                                    // длине и ширине...?
    if (area2 <= 0)
    {
        std::cout << "Неположительная площадь\n";
        exit(1);
    }
    int area3 = FramedArea(y,z);
    if (area3 <= 0)
    {
        std::cout << "Неположительная площадь\n";
        exit(1);
    }
    double ratio = double(area1)/area3;
    return 0;
}

int main()
{
    F(5,4,3);
    return 0;
}
