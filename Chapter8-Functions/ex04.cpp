/*
    Переменная типа int может хранить целые числа, не превышающие некоторого максимального числа.
    Вычислите приближение этого максимального числа с помощью функции fibonacci()

    Приближением максимального числа является число 1836311903.
*/

#include <iostream>
#include <vector>

void Fibonacci(int firstElem, int secondElem, std::vector<int>& myVector, int countOfElements)
{
    if (countOfElements < 2) throw std::invalid_argument("Количество элементов должно быть >= 2!");
    myVector.push_back(firstElem);
    myVector.push_back(secondElem);
    for (int i = 2; i < countOfElements; ++i)
    {
        myVector.push_back(myVector[i - 2] + myVector[i - 1]);
    }
}

void Print(std::string str, const std::vector<int>& vec)
{
    std::cout << str << ": ";
    for (int elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

int main()
try
{
    std::vector<int> emptyVector;
    Fibonacci(5, 8, emptyVector, 45);
    Print("Вектор с числами Фибоначчи", emptyVector);
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
}
