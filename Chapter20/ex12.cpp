/*
    Завершите определение класса list из разделов 20.4.1 и 20.4.2 и продемонстрируйте работу функции
    high(). Выделите память для объекта класса Link, представляющего узел, следующий за концом списка.
*/

#include <iostream>
#include "include/list.h"

template<typename Iter>
Iter High(Iter first, Iter last)
{
    Iter hight = first;
    for (Iter it = first; it != last; ++it) {
        if (*it > *hight) {
            hight = it;
        }
    }
    return hight;
}

int main()
try
{
    list<int> lst;
    
    for (int x; std::cin >> x;) {
        lst.push_back(x);
    }
    
    for (int x : lst) {
        std::cout << x << '\n';
    }
    std::cout << "---------------\n";
    
    list<int>::iterator it = High(lst.begin(), lst.end());
    if (it == lst.end()) {
        std::cout << "Список пуст!\n";
    } else {
        std::cout << "Highest value: " << *it << '\n';
    }
    
    return 0;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
