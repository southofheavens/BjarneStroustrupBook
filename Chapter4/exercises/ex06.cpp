/*
 * Создайте вектор, хранящий десять строковых значений "zero", "one", ... "nine". Используйте его
 * в программе, преобразующей цифру в соответствующее стороковое представление; например, при вводе 
 * цифры 7 на экран должна быть  выведена строка seven. С помощью этой же программы, используя тот 
 * же цикл ввода преобразуйте строковое представление цифры в числовое; например, при вводе строки
 * seven на экран должна быть выведена цифра 7.
 * 
 * How to compile:
 * clang++ -std=c++14 ex06.cpp
 */

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine"};
    std::string input;
    std::cin >> input;
    if (input.length() == 1 && isdigit(input[0])) {
        std::cout << digits[input[0] - '0'] << '\n';
    }
    else
    {
        bool isThisDigit = false;
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] == input)
            {
                std::cout << i << '\n';
                isThisDigit = true;
            }
        }
        if (!isThisDigit) {
            std::cout << "Вы ввели некорректное значение!\n";
        }
    }
    return 0;
}
