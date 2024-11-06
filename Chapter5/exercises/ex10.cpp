/*
 * Измените программу из упр. 8 так, чтобы она использовала тип double вместо int. Кроме того, создайте
 * вектор действительных чисел, содержащий N - 1 разностей между соседними величинами, и выведите этот
 * вектор на печать.
 *
 * How to compile:
 * clang++ -std=c++14 ex10.cpp 
 */

#include <iostream>
#include <vector>

int main()
try
{
    std::cout << "Введите количество суммируемых значений: ";
    int n;
    std::cin >> n;
    if (n <= 0) 
    {
        throw std::invalid_argument("Количество суммируемых значений должно быть > 0!");
    }
    std::cout << "Введите несколько целых чисел (Enter, CTRL+D для окончания ввода)\n";
    std::vector<double> numbers;
    for(double number; std::cin >> number;)
    {
        numbers.push_back(number);
    }
    if (n > numbers.size()) 
    {
        throw std::invalid_argument("Количество суммируемых значений превышает число введённых вами значений!");
    }
    std::cout << "Сумма первых " << n << " чисел (";
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += numbers[i];
        if (i != n - 1)
        {
            std::cout << numbers[i] << " ";
        }
        else
        {
            std::cout << numbers[i];
            std::cout << ") равна " << sum << ".\n";
        }
    }
    std::vector<double> differences(numbers.size() - 1);
    for (int i = 0; i < numbers.size() - 1; ++i)
    {
        differences[i] = numbers[i] - numbers[i + 1];
    }
    for (double number : differences)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
    exit(1);
}
