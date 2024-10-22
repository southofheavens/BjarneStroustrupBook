/*
    Реализуйте распределитель памяти (см. раздел 19.3.7), используя функции malloc() и free() (раздел Б.11.4).
    Создайте класс vector так, как описано в конце раздела 19.4, для работы с несколькими простыми тестовыми
    примерами. Указание: поищите "размещающий new" и "явный вызов деструктора" в полном справочнике по C++.
*/

#include "vector.h"
#include <iostream>

template<typename T>
void PrintVec(const vector<T>& someVec)
{
    for (int i = 0; i < someVec.size(); ++i)
    {
        std::cout << someVec[i];
        i != someVec.size() - 1 ? std::cout << ' ' : std::cout << '\n';
    }
}

vector<int> SomeVec()
{
    vector<int> sv{1,4,9,16,25};
    return sv;
}

int main()
{
    vector<int> vec1{1,2,3,4,5,6,7,8,9,0};
    PrintVec(vec1);
    
    vec1.resize(5);
    PrintVec(vec1);
    
    vec1.resize(15);
    PrintVec(vec1);
    
    vector<int> vec2{vec1};
    PrintVec(vec2);
    
    vector<int> vec3 = vec2;
    PrintVec(vec3);
    
    vector<int> vec4{SomeVec()};
    PrintVec(vec4);
    
    vector<int> vec5 = SomeVec();
    PrintVec(vec5);
    
    return 0;
}
