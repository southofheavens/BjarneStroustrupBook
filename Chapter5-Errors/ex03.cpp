/*
    Самой низкой температурой является абсолютный нуль, т.е. -273.15°C, или 0K. Даже после исправления
    приведения выше программа выводит неверные результаты для температуры ниже абсолютного нуля. Поместите
    в функцию main() проверку, которая будет выводить сообщение об ошибке для температур ниже -273.15°C.
*/

#include <iostream>

double ctok(double c)  // Преобразует температуру
{                      // в градусах Цельсия
                       // в температуру в градусах Кельвина
    double k = c + 273.15;
    return k;
}

int main() 
{
    double c = 0;           // Объявляем входную переменную
    std::cin >> c;               // Вводим температуру
    if (c < 273.15)
    {
        std::cerr << "Температура ниже абсолютного нуля!\n";
        exit(1);
    }
    double k = ctok(c);   // Преобразуем температуру
    std::cout << k << '\n';      // Выводим температуру
    return 0;
}
