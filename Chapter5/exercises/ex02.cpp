/*
 * Следующая программа получает температуру в градусах Цельсия и преобразует ее в температуру в градусах
 * Кельвина. Этот исходный текст содержит много ошибок. Найдите ошибки, перечислите их и исправьте
 * программу.
 *
 * double ctok(double c)  // Преобразует температуру
 * {                      // в градусах Цельсия
 *                        // в температуру в градусах Кельвина
 *     int k = c + 273.15;
 *     return int;
 * }
 * 
 * int main() 
 * {
 *     double c = 0;           // Объявляем входную переменную
 *     cin >> d;               // Вводим температуру
 *     double k = ctok("c");   // Преобразуем температуру
 *     Cout << k << '/n';      // Выводим температуру
 * }
 *
 *  Ошибки, которые я нашел:
 *  > 9 строка: тип переменной k должен быть не int, а double, так как тип возвращаемого
 *  значения функции равен double;
 *  > 10 строка: вместо return int необходимо написать return k;
 *  > 15 строка: переменную c не обязательно инициализировать, так как в следующей строке
 *  мы введём нужное нам значение для данной переменной, поэтому я бы написал double c;
 *  > 16 строка: неправильное название переменной, вместо cin >> d необходимо написать cin >> c;
 *  > 17 строка: неверный тип аргумента, передаваемого функцию. Вместо того, чтобы передать функцию
 *  c со значением double, в функцию передаётся строчка "c". Чтобы исправить код, необходимо написать
 *  double k = ctok(c);
 *  > 18 строка: здесь ошибки две: Cout написан с большой буквы и в '/n' косая черта направлена не
 *  в ту сторону. Так выглядит исправленный вариант строки: cout << k << '\n';
 *  ---
 * Ну и в конце желательно было бы написать return 0;
 * 
 * How to compile:
 * clang++ -std=c++14 ex02.cpp
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
    double c;           // Объявляем входную переменную
    std::cin >> c;               // Вводим температуру
    double k = ctok(c);   // Преобразуем температуру
    std::cout << k << '\n';      // Выводим температуру
    return 0;
}
