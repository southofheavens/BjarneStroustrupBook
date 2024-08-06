/*
    Напишите программу, считывающую цифры и составляющую из них целые числа. Например, число 123
    считывается как последовательность символов 1, 2 и 3. Программа должна вывести на экран
    сообщение "123 - это 1 сотня, 2 десятки и 3 единицы". Число должно быть выведено как значение
    типа int. Обрабатывайте числа, состоящие из одной цифры, двух, трех и четырех цифр.
    Указание: для того, чтобы получить число 5 из символа '5', вычтите из него символ '0',
    иначе говоря, '5'-'0'=5.
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string number;
    std::cin >> number;
    std::vector<char> symbols;
    for (int i = 0; i < number.length(); ++i)
    {
        symbols.push_back(number[i]);
    }
    int integerNumber = 0;
    int factor = 1;
    for (int i = symbols.size() - 1; i >= 0; --i)
    {
        integerNumber += (symbols[i] - '0') * factor;
        factor *= 10;
    }
    std::cout << integerNumber << " - это ";
    int index = 0;
    switch (symbols.size())
    {
        case 4:
            std::cout << symbols[index] << " тысяч, ";
            index++;
        case 3:
            std::cout << symbols[index] << " сотен, ";
            index++;
        case 2:
            std::cout << symbols[index] << " десятков и ";
            index++;
        case 1:
            std::cout << symbols[index] << " единиц.\n";
            index++;
            break;
        case 0:
            std::cout << "ничего\n";
    }
    return 0;
}