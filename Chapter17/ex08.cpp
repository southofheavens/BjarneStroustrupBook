/*
    Выполните упр. 7 еще раз, но теперь считывайте символы в строку std::string, а не в динамическую
    память (класс string знает, как использовать динамическую память).
*/

#include <iostream>
#include <string>

int main()
{
    std::string result = "";
    char ch;
    while(std::cin.get(ch) && ch != '!')
    {
        result += ch;
    }
    std::cout << result << '\n';
    return 0;
}
