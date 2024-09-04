/*
    Напишите шаблонную функцию f(), складывающую элементы одного вектора vector<T> с элементами
    другого такого вектора; например, f(v1,v2) должна выполнить суммирование v1[i]+=v2[i] для
    каждого элемента v1.
*/

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void F(std::vector<T>& f, const std::vector<T>& s)
{
    if (f.size() != s.size()) {
        std::cerr << "Размеры векторов не совпадают.\n"; exit(1);
    }
    for (int i = 0; i < f.size(); ++i)
    {
        f[i] += s[i];
    }
}

int main()
{
    std::vector<std::string> first{"a","b","c"};
    std::vector<std::string> second{"d","e","f","g","h"};
    F(first,second);
    for (std::string elem : first)
    {
        std::cout << elem << '\n';
    }
    return 0;
}
