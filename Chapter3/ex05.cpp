/*
 * Измените программу так, чтобы она просила пользователя ввести два числа с плавающей точкой
 * и сохраняла их в переменных типа double. Сравните результаты работы этих двух программ
 * для некоторых входных данных на ваш выбор. Совпадают ли эти результаты? Должны ли они
 * совпадать? Чем они различаются?
 */

#include <iostream>

int main()
{
    std::cout << "Введите два числа с плавающей точкой через пробел: ";
    double val1;
    double val2;
    std::cin >> val1 >> val2;
    double max;
    double min;
    if (val1 > val2)
    {
        max = val1;
        min = val2;
    }
    else
    {
        max = val2;
        min = val1;
    }
    std::cout << "Наибольшее значение: " << max << ". Наименьшее значение: " << min << ".\n";
    std::cout << "Сумма: " << val1 + val2 << ". Разность: " << val1 - val2 << ".\n";
    std::cout << "Произведение: " << val1 * val2 << ". Частное: " << val1 / val2 << ".\n";
    return 0; 
}
