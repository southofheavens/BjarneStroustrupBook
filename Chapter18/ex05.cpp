/*
    Напишите функцию string cat_dot(const string&s1, const string&s2), выполняющую конкатенацию двух
    строк с точкой между ними. Например, вызов cat_dot("Нильс","Бор") должен вернуть строку
    Нильс.Бор.
*/

#include <iostream>
#include <string>

std::string CatDot(const std::string& s1, const std::string& s2)
{
    return s1 + '.' + s2;
}

int main()
{
    std::cout << CatDot("Нильс","Бор") << '\n';
    return 0;
}
