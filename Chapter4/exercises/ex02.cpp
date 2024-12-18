/*
 * Допустим, мы определяем медиану последовательности как "число, относительно которого ровно половина
 * элементов меньше, а другая половина - больше". Исправьте программу из раздела 4.6.2 так, чтобы она
 * всегда выводила медиану. Подсказка: медиана не обязана быть элементом последовательности.
 * 
 * How to compile:
 * clang++ -std=c++14 ex02.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm> // для функции sort()

int main()
{
    std::vector<double> temps; // Температуры
    for(double temp; std::cin >> temp; ) { // Чтение в temp
        temps.push_back(temp);
    }

    // Вычисление средней температуры:
    double sum = 0;
    for (int x : temps) {
        sum += x;
    }
    std::cout << "Средняя температура: " << sum / temps.size() << '\n';

    // Вычисление медианы температуры:
    // В книге написано sort(temps), но в моем случае такой код не сработает
    // Если вы не подключаете "std_lib_facilities.h", то нужно написать как я
    sort(temps.begin(), temps.end()); // Сортировка вектора температур

    if (temps.size() % 2 == 1) {
        std::cout << "Медианная температура: " << temps[temps.size() / 2] << '\n';
    }
    else 
    {
        std::cout << "Медианная температура: " 
        << (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2 << '\n';
    }
    return 0;
}
