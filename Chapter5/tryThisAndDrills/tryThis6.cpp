/*
 * Просмотрите программу. Используя достоверные источники информации, выберите разумные значения для
 * констант min_temp ("минимальная температура") и max_temp ("максимальная температура"). Эти значения
 * определят пределы применимости вашей программы
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis6.cpp
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<double> temps;

    for (double temp; std::cin >> temp; ) {
        temps.push_back(temp);
    }

    double sum = 0;
    double highTemp = INT_MIN;
    double lowTemp = INT_MAX;
    
    std::cout << highTemp << ' ' << lowTemp << '\n';

    for (int x : temps) 
    {
        if (x > highTemp) {
            highTemp = x;
        }
        if (x < lowTemp) {
            lowTemp = x;
        }
        sum += x;
    }

    std::cout << "Максимальная температура: " << highTemp << '\n';
    std::cout << "Минимальная температура: " << lowTemp << '\n';
    std::cout << "Средняя температура: " << sum/temps.size() << '\n';
    return 0;
}
