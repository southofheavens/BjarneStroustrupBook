/*
    Реализуйте простой класс unique_ptr, содержащий только конструктор, деструктор, операторы -> и *, а также
    функцию release(). В частности, не пытайтесь реализовать присваивание или копирующий конструктор.
*/

#include <iostream>
#include <vector>

template <typename T>
class MyPtr
{
public:
    MyPtr() { p = new T; }

    explicit MyPtr(T* p) : p{p} {}

    ~MyPtr() { delete p; }
    
    T* Release() 
    {
        T* newP = p;
        p = nullptr;
        return newP;
    }
    
    T& operator*() { return *p; }
    
    T* operator->() { return p; }
    
private:
    T* p;
};

int main()
{
    MyPtr<std::vector<int>> a{new std::vector<int> {1,2,3,4,5}};
    a->push_back(6);
    
    for (int i = 0; i < a->size(); ++i) {
        std::cout << (*a)[i] << '\n';
    }
    
    return 0;
}
