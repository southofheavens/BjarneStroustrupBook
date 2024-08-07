/*
    Выполните упр. 6 для трех строковых значений. Так, если пользователь вводит значения Steinbeck,
    Hemingway, Fitzgerald, то вывод программы должен имеет вид Fitzgerald, Hemingway, Steinbeck.
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Введите три слова через пробел: ";
    std::string first;
    std::string second;
    std::string third;
    std::cin >> first >> second >> third;
    std::string max;
    std::string medium;
    std::string min;
    if (first >= second && first >= third) // если первое слово >= второго и третьего
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
    else if (second >= first && second >= third) // если второе слово >= первого и третьего
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
    else // если третье слово >= первого и второго
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
