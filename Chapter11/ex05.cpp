/*
    Напишите программу, считывающую строки и выводящую категории каждого символа в соответствии с правилами,
    описанными в разделе 11.6. Помните, что один и тот же символ может относиться к разным категориям (например,
    x - это и буквенный, и буквенно-цифровой символ).
*/

#include <iostream>
#include <string>

int main()
{
    std::string string;
    while (getline(std::cin, string))
    {
        char ch;
        for (int i = 0; i < string.length(); ++i)
        {
            ch = string[i];
            if (isspace(ch))
            {
                std::cout << ch << " - пробельный символ\n";
            }
            else if (isalpha(ch))
            {
                std::cout << ch << " - буква\n";
            }
            else if (isdigit(ch))
            {
                std::cout << ch << " - цифра\n";
            }
            else
            {
                std::cout << ch << " имеет другой тип\n";
            }
        }
    }
    return 0;
}
