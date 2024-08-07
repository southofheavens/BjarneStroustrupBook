/*
    Напишите программу, создающую файл из данных, записанных в виде объектов класса Reading, определенного
    в разделе 10.5. Для проверки заполните файл как минимум 50 показаниями температуры. Назовите эту программу
    store_temps.cpp, а создаваемый файл - raw_temps.txt.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

struct Reading
{
    int hour;
    int temperature;
};

int main()
{
    srand((unsigned int)time(NULL));
    
    std::vector<Reading> data;
    
    for (int i = 0; i < 50; ++i)
    {
        Reading elem;
        elem.hour = rand() % 24;
        elem.temperature = rand() % 130 - 30;
        data.push_back(elem);
    }
    
    std::fstream ofs;
    ofs.open("raw_temps.txt", std::ios_base::out);
    
    for (Reading elem : data)
    {
        ofs << elem.hour << ' ' << elem.temperature << '\n';
    }
    
    ofs.close();
    return 0;
}
