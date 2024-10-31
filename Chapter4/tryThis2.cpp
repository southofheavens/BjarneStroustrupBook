/*
 * Перепишите программу преобразования валют из предыдущего раздела, используя инструкцию switch. Добавьте
 * конвертацию евро и фунта стерлингов. Какую из версий программы легче писать, понимать и модифицировать?
 * Почему?
 * 
 * Легче писать, понимать и модифицировать версию программы, использующую конструкцию switch потому, что эта
 * конструкция нагляднее и более ясна при использовании набора констант.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis2.cpp
 */

#include <iostream>

int main()
{
    constexpr double HRYVNIA_TO_DOLLARS = 0.024;
    constexpr double RUBLES_TO_DOLLARS = 0.01;
    constexpr double YUAN_TO_DOLLARS = 0.14;
    constexpr double EURO_TO_DOLLARS = 1.09;
    constexpr double POUND_STERLING_TO_DOLLARS = 1.3;
    double money;
    char currency;
    std::cout << "Пожалуйста, введите количество валюты и саму валюту (h, r, y, e или l):\n";
    std::cin >> money >> currency;
    switch (currency)
    {
        case 'h':
            std::cout << "В " << money << " гривнах " << money*HRYVNIA_TO_DOLLARS << " долларов.\n";
            break;
        case 'r':
            std::cout << "В " << money << " рублях " << money*RUBLES_TO_DOLLARS << " долларов.\n";
            break;
        case 'y':
            std::cout << "В " << money << " юанях " << money*YUAN_TO_DOLLARS << " долларов.\n";
            break;
        case 'e':
            std::cout << "В " << money << " евро " << money*EURO_TO_DOLLARS << " долларов.\n";
            break;
        case 'l':
            std::cout << "В " << money << " фунтах стерлингов " << money*POUND_STERLING_TO_DOLLARS << " долларов.\n";
            break;
        default:
            std::cout << "Извините, я не знаю, что такое " << currency << ".\n";
            break;
    }
    return 0;
}
