/*
    Определите класс pvector, похожий на вектор указателей, с тем отличием, что он содержит указатели
    на объекты, а его деструктор уничтожает все объекты, на которые указывают указатели-элементы.
*/

#include "include/pvector.h"
#include <iostream>

struct Cat
{
private:
    int* height;

public:
    Cat(int h)
    {
        height = new int(h);
    }
    
    void Print()
    {
        std::cout << *height << '\n';
    }
    
    ~Cat()
    {
        delete height;
    }
};

int main()
{
    pvector<Cat*> pvec;
    
    pvec.push_back(new Cat(1));
    pvec.push_back(new Cat(2));
    pvec.push_back(new Cat(3));
    
    for (int i = 0; i < pvec.size(); ++i)
    {
        pvec[i]->Print();
    }
    
    return 0;
}
