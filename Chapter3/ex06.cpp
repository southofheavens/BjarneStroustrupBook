/*
    Напишите программу, предлагающую пользователю ввести три целых числа, а затем выводит их в порядке
    возрастания, разделяя запятыми. Например, если пользователь вводит числа 10 4 6, то программа
    должна вывести на экран числа 4, 6, 10. Если два числа совпадают, то они должны идти одно за
    другим. Например, если пользователь вводит числа 4 5 4, то программа должна вывести на экран
    4, 4, 5.
*/

#include <iostream>

int main()
{
    std::cout << "Введите три целых числа через пробел: ";
    int first;
    int second;
    int third;
    std::cin >> first >> second >> third;
    int max;
    int medium;
    int min;
    if (first >= second && first >= third) // если первое число >= второго и третьего
    {
        max = first;
        if (second >= third)
        {
            medium = second;
            min = third;
        }
        else
        {
            medium = third;
            min = second;
        }
    }
    else if (second >= first && second >= third) // если второе число >= первого и третьего
    {
        max = second;
        if (first >= third)
        {
            medium = first;
            min = third;
        }
        else
        {
            medium = third;
            min = first;
        }
    }
    else // если третье число >= первого и второго
    {
        max = third;
        if (first >= second)
        {
            medium = first;
            min = second;
        }
        else
        {
            medium = second;
            min = first;
        }
    }
    std::cout << min << ", " << medium << ", " << max << ".\n";
    return 0;
}
