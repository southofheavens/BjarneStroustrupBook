/*
    Напишите программу, считывающую данные данные из файла raw_temps.txt, созданого в упр. 2, в вектор,
    а затем вычислите среднее значение и медиану температур. Назовите программу temps_stats.cpp.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Reading
{
    int hour;
    double temperature;
};

bool comp(Reading& first, Reading& second) // Используется для sort
// Если вы не знаете, что это такое, можно успешно отсортировать массив и без компоратора
{
    return first.temperature < second.temperature;
}

int main()
{
    std::fstream ifs;
    ifs.open("raw_temps.txt", std::ios_base::in);
    
    std::vector<Reading> data;
    
    int hour;
    double temperature;
    while (ifs >> hour >> temperature)
    {
        data.push_back(Reading{hour, temperature});
    }
    sort(data.begin(), data.end(), comp);

    double median;
    if (data.size() % 2 != 0)
    {
        median = data[data.size() / 2].temperature;
    }
    else
    {
        median = data[data.size() / 2].temperature + data[data.size() / 2 - 1].temperature;
    }
    
    double average = 0;
    for (Reading elem : data)
    {
        average += elem.temperature;
    }
    average /= (double)data.size();
    
    std::cout << "Среднее значение: " << average << ", медиана: " << median << '\n';
    return 0;
}
