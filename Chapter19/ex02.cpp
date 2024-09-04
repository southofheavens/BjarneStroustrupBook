/*
    Напишите шаблонную функцию, получающую в качестве аргументов объекты типов vector<T> vt и
    vector<U> vu и возвращающую сумму всех произведений vt[i]*vu[i].
*/

#include <iostream>
#include <vector>

template <typename T, typename U>
double Sum(std::vector<T> vt, std::vector<U> vu)
{
    if (vt.size() != vu.size()) {
        std::cerr << "Размеры векторов не совпадают.\n"; exit(1);
    }
    double sum = 0;
    for (int i = 0; i < vt.size(); ++i)
    {
        sum += vt[i] * vu[i];
    }
    return sum;
}

int main()
{
    std::vector<int> arr{1,2,3,4,5};
    std::vector<double> arr2{1.5,2,3,4,5.5};
    double sum = Sum(arr,arr2);
    std::cout << sum << '\n';
    return 0;
}
