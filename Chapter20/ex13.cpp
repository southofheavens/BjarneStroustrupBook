/*
    На самом деле в классе list нам не нужен реальный объект класса Link, расположенный за последним элементом.
    Модифицируйте свое решение из предыдущего упражнения так, чтобы в качестве указателя на несуществующий
    объект класса Link (list<Elem>::end()) использовалось значение 0; иначе говоря, размер пустого списка может
    быть равен размеру отдельного указателя.
 
    При таком способе реализации структуры данных есть минусы: для выполнения операций push_back() и pop_back()
    нам необходимо "пробежаться" по всему списку от первого до последнего элемента. В предыдущей реализации мы
    просто вставляли элемент между last->prev и last или удаляли нужный нам элемент last->prev.
*/

#include <iostream>
#include "include/list2.h"

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