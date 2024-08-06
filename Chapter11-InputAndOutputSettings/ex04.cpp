/*
    Напишите программу под названием multi_input.cpp, которая предлагает пользователю ввести несколько
    целых восьмеричных, десятичных и шестнадцатеричных чисел в любом сочетании, используя суффиксы
    0 и 0x; правильно интерпретируйте эти числа и преобразуйте их в десятичный вид. Ваша программа
    должна выводить на экран примерно такие результаты:
    0x43  (шестнадцатеричное)  превращается в десятичное 67
    0123  (восьмеричное)       превращается в десятичное 83
    65    (десятичное)         превращается в десятичное 65
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> numbers;
    int maxLength = 0;
    for(std::string string; std::cin >> string; )
    {
        if (string.length() > maxLength)
        {
            maxLength = string.length();
        }
        numbers.push_back(string);
    }
    
    for(std::string number : numbers)
    {
        std::cout << number << '\t';
        if (number[0] == '0')
        {
            if (number[1] == 'x')
            {
                std::cout <<"(шестнадцатеричное) ";
            }
            else
            {
                std::cout << "(восьмеричное)      ";
            }
        }
        else
        {
            std::cout << "(десятичное)        ";
        }
        std::cout << "превращается в десятичное ";

        std::stringstream ss{number};
        ss.unsetf(std::ios::dec);
        ss.unsetf(std::ios::hex);
        ss.unsetf(std::ios::oct);
        int intNumber;
        ss >> intNumber;
        std::cout << intNumber << '\n';
    }
    return 0;
}
