/*
    Напишите функцию print(), которая выводит в поток cout вектор целых чисел. Передавайте ей два 
    аргумента: строку для "метки" результатов и объект класса vector.
*/

#include <iostream>
#include <string>
#include <vector>

void Print(std::string str, const std::vector<int>& vec)
{
    std::cout << str << ": ";
    for (int elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<int> numbers {1, 2, 3, 4, 5};
    Print("Вектор чисел от 1 до 5", numbers);
    return 0;
}
