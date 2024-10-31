/*
 * Используя приведенный выше пример, напишите программу для перевода гривен, рублей и юаней в доллары.
 * Если вы любите реализм, уточните обменные курсы в интернете.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis1.cpp
 */

#include <iostream>

int main()
{
    constexpr double HRYVNIA_TO_DOLLARS = 0.024;
    constexpr double RUBLES_TO_DOLLARS = 0.01;
    constexpr double YUAN_TO_DOLLARS = 0.14;
    double money;
    char currency;
    std::cout << "Пожалуйста, введите количество валюты и саму валюту (h, r или y):\n";
    std::cin >> money >> currency;
    if (currency == 'h') {
        std::cout << "В " << money << " гривнах " << money*HRYVNIA_TO_DOLLARS << " долларов.\n";
    }
    else if (currency == 'r') {
        std::cout << "В " << money << " рублях " << money*RUBLES_TO_DOLLARS << " долларов.\n";
    }
    else if (currency == 'y') {
        std::cout << "В " << money << " юанях " << money*YUAN_TO_DOLLARS << " долларов.\n";
    }
    else {
        std::cout << "Извините, я не знаю, что такое " << currency << '\n';
    }
    return 0;
}
