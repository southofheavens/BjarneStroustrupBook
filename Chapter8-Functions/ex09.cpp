/*
    Напишите функцию maxv(), возвращающую наибольший элемент вектора, передаваемого в качестве аргумента.
*/

#include <iostream>
#include <vector>

int Maxv(const std::vector<int>& myVector)
{
    int maxElem = INT_MIN;
    for (int elem : myVector)
    {
        if (elem > maxElem)
        {
            maxElem = elem;
        }
    }
    return maxElem;
}

int main()
{
    std::vector<int> numbers {-1000, 2, 0, 500, 1000000, 1000000000, 19, 543210};
    int maxElem = Maxv(numbers);
    std::cout << maxElem << '\n';
    return 0;
}
