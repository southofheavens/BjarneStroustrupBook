/*
    Модифицируйте функцию cat_dot() из предыдущего упражнения так, чтобы в качестве третьего аргумента
    она получала строку, используемую как разделитель (вместо точки).
*/

#include <iostream>
#include <string>

std::string CatDot(const std::string& s1, const std::string& s2, const std::string& sep)
{
    return s1 + sep + s2;
}

int main()
{
    std::cout << CatDot("Нильс","Бор","---") << '\n';
    return 0;
}
