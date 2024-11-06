/*
 * Напишите программу, находящую все простые числа между 1 и 100. Для решения этой задачи существует
 * классический метод "Решето Эратосфена". Если этот метод вам неизвестен, поищите его описание
 * в Интернете. Напишите программу, использующую этот метод.
 * 
 * How to compile:
 * clang++ -std=c++14 ex13.cpp
 */  

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    for (int i = 0; i <= 100; ++i)
    {
        numbers.push_back(i);
    }

    std::vector<int> primeNumbers;
    for (int i = 2; i <= 100; ++i)
    {
        if (numbers[i] != 0)
        {
            primeNumbers.push_back(i);
            for (int j = i * i; j <= 100; j += i)
            {
                numbers[j] = 0;
            }
        }
    }

    for (int number : primeNumbers)
    {
        std::cout << number << '\n';
    }
    return 0;
}
