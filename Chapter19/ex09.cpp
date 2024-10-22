/*
    Повторите реализацию функции vector::operator=() (раздел 19.2.5), используя распределитель памяти
    (раздел 19.3.7) для управления памятью.
*/

#include <iostream>
#include "vector.h"

int main()
{
    vector<int> vec{1,2,3};
    
    vector<int> vec2;
    vec2 = vec;
    
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << '\n';
    }
    return 0;
}
