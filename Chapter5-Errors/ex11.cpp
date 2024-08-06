/*
    Напишите программу, вычисляющую начальный отрезок последовательности Фибоначчи, т.е. последовательности,
    начинающейся с чисел 1 1 2 3 5 8 13 21 34. Каждое число в этой последовательности равно сумме двух
    предыдущих. Найдите наибольшее число Фибоначчи, которое можно записать в переменную типа int.
*/

#include <iostream>
#include <vector>

std::vector<int> Fibonacci(int length)
{
    if (length <= 0) throw std::invalid_argument("Длина отрезка должна быть >0 !");
    switch(length)
    {
        case 1:
            return {1};
        case 2:
            return {1, 1};
        default:
            std::vector<int> result = {1, 1};
            for (int i = 2; i < length; ++i)
            {
                result.push_back(result[i - 2] + result[i - 1]);
            }
            return result;
    }
}

void MaxNumOfFibonacciInInteger()
{
    int firstNumber = 1;
    int secondNumber = 1;
    int thirdNumber = firstNumber + secondNumber;
    while (thirdNumber > 0)
    {
        firstNumber = secondNumber;
        secondNumber = thirdNumber;
        thirdNumber = firstNumber + secondNumber;
    }
    std::cout << "Наибольшее число Фибоначчи, которое можно поместить в int: " << secondNumber << '\n';
}

int main()
try
{
    std::cout << "Введите длину начального отрезка последовательности Фибоначчи: ";
    int length;
    std::cin >> length;
    std::vector<int> result = Fibonacci(length);
    for (int number : result)
    {
        std::cout << number << " ";
    }
    std::cout << '\n';
    MaxNumOfFibonacciInInteger();
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
}
