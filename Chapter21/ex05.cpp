/*
    Что нам следовало бы сделать, если бы мы не могли вернуть итератор end(), означающий, что элемент не
    найден? Заново спроектируйте и реализуйте алгоритмы find() и count() так, чтобы они получали итераторы,
    указывающие на первый и последний элементы. Сравните результаты со стандартными версиями.
*/

#include <iostream>
#include <vector>
#include <cstdint>

template<typename InputIterator, typename Elem>
bool Find(InputIterator first, InputIterator last, const Elem& el)
{
    InputIterator it = first;
    while (it <= last)
    {
        if (*it == el) {
            return true;
        }
        ++it;
    }
    return false;
}

template<typename InputIterator, typename Elem>
uint32_t Count(InputIterator first, InputIterator last, const Elem& el)
{
    uint32_t result = 0;
    InputIterator it = first;
    while (it <= last)
    {
        if (*it == el) {
            result++;
        }
        ++it;
    }
    return result;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,15,6,6,6,14,6,55};
    std::cout << Find(vec.begin(),(--vec.end()),55) << '\n';
    std::cout << Find(vec.begin(),(--vec.end()),25) << '\n';
    
    std::cout << Count(vec.begin(),(--vec.end()),6) << '\n';
    return 0;
}
