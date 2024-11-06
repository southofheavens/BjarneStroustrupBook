/*
 * Модифицируйте мини-калькулятор, описанный в упр.5, так, чтобы он принимал на вход цифры, записанные
 * как в числовом, так и в строковом формате.
 * 
 * How to compile:
 * clang++ -std=c++14 ex07.cpp
 */

#include <iostream> 
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine"};
    std::string dig1;
    std::string dig2;
    char operation;
    std::cin >> dig1 >> dig2 >> operation;
    int integerDig1;
    int integerDig2;

    if (dig1.length() == 1 && isdigit(dig1[0])) {
        integerDig1 = dig1[0] - '0';
    }
    else
    {
        bool isThisDigit = false;
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] == dig1)
            {
                integerDig1 = i;
                isThisDigit = true;
            }
        }
        if (!isThisDigit) {
            std::cout << "Вы ввели некорректное значение!\n";
        }
    }

    if (dig2.length() == 1 && isdigit(dig2[0])) {
        integerDig2 = dig2[0] - '0';
    }
    else
    {
        bool isThisDigit = false;
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] == dig2)
            {
                integerDig2 = i;
                isThisDigit = true;
            }
        }
        if (!isThisDigit) {
            std::cout << "Вы ввели некорректное значение!\n";
        }
    }

    switch(operation)
    {
        case '+':
            std::cout << "Сумма " << integerDig1 << " и " << integerDig2 << " равна " << integerDig1 + integerDig2 << '\n';
            break;
        case '-':
            std::cout << "Разность " << integerDig1 << " и " << integerDig2 << " равна " << integerDig1 - integerDig2 << '\n';
            break;
        case '*':
            std::cout << "Произведение " << integerDig1 << " и " << integerDig2 << " равно " << integerDig1 * integerDig2 << '\n';
            break;
        case '/':
            if (integerDig2 == 0) {
                std::cout << "Деление на ноль запрещено!\n";
            }
            else
            {
                std::cout << "Частное " << integerDig1 << " и " << integerDig2 << " равно "
                    << integerDig1 / (double)integerDig2 << '\n';
            }
            break;
        default:
            std::cout << "Введена некорректная операция!\n";
            break;
    }
    return 0;
}
