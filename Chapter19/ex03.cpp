/*
    Напишите шаблонный класс Pair, содержащий пары значений любого типа. Используйте его для
    реализации простой таблицы символов, такой как в калькуляторе из раздела 7.8.
*/

#include <iostream>
#include <string>

template <typename T1, typename T2>
struct Pair
{
    Pair() {}
    T1 first;
    T2 second;
};

int main()
{
    Pair<std::string, int> pair;
    pair.first = "hello";
    pair.second = 500;
    std::cout << pair.first << ' ' << pair.second << std::endl;
    return 0;
}
