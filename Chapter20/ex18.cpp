/*
    Определите итератор с проверкой выхода за пределы допустимого диапазона для класса vector (итератор с
    произвольным доступом).
*/

#include <iostream>
#include "include/vector.h"

struct Cat
{
    void Meow()
    {
        std::cout << "Meow\n";
    }
};

int main()
try
{
    vector<int> myVector{1,2,3,4,5,6,7,8,9};
    
    for (int i = 0; i < myVector.size(); ++i) {
        myVector[i] *= myVector[i];
    }
    
    for (const int x : myVector) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    
    auto it = myVector.begin();
    std::cout << *it << ' ';
    it += 5;
    std::cout << *it << ' ';
    it = it + 3;
    std::cout << *it << '\n';
    std::cout << (it - myVector.begin()) << '\n';
    
    vector<Cat> cats;
    Cat c;
    cats.push_back(c);
    vector<Cat>::iterator catIt = cats.begin();
    catIt->Meow();
    
    // Выход за пределы
    --catIt;
    
    return 0;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
