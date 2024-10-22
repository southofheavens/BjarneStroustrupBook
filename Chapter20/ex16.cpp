/*
    Определите класс ovector, похожий на класс pvector, с тем отличием, что операции [] и * возвращают не
    указатели, а ссылки на объекты, на которые указывают соответствующие элементы.
*/

#include "include/ovector.h"
#include <iostream>

int main()
{
    ovector<int*> vec;
    vec.push_back(new int(5));
    vec.push_back(new int(6));
    vec.push_back(new int(7));
    
    ovector<int*>::iterator it = vec.begin();
    std::cout << *it << '\n' << "------\n";
    
    for (const int x : vec) {
        std::cout << x << '\n';
    }
    std::cout << "------\n";

    for (int i = 0; i < vec.size(); ++i) {
        vec[i] *= vec[i];
    }

    for (const int x : vec) {
        std::cout << x << '\n';
    }

    return 0;   
}