/*
    Напишите программу, считывающую и сохраняющую ряд целочисленных значений, а затем вычисляющую
    сумму первых N чисел. Запросите значение N, считайте значения в vector и вычислите сумму
    первых N значений. Например:

    Введите количество суммируемых значений:
    3
    Введите несколько целых чисел (| для окончания ввода):
    12 23 13 24 15 |
    Сумма первых 3 чисел (12 23 13)  равна 48.

    Обрабатывайте любые входные данные. Например, если пользователю потребуется просуммировать
    чисел больше, чем сохранено в векторе, выводите соответствующее сообщение.
*/

#include <iostream>
#include <vector>

int main()
try
{
    std::cout << "Введите количество суммируемых значений: ";
    int n;
    std::cin >> n;
    if (n < 0) 
    {
        throw std::invalid_argument("Количество суммируемых значений должно быть >= 0!");
    }
    std::cout << "Введите несколько целых чисел (Enter, CTRL+D для окончания ввода)\n";
    std::vector<int> numbers;
    for(int number; std::cin >> number;)
    {
        numbers.push_back(number);
    }
    if (n > numbers.size()) 
    {
        throw std::invalid_argument("Количество суммируемых значений превышает число введённых вами значений!");
    }
    std::cout << "Сумма первых " << n << " чисел (";
    for (int i = 0, sum = 0; i < n; ++i)
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
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
    exit(1);
}
