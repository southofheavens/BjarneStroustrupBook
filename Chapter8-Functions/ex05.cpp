/*
    Напишите две функции, обращающие порядок следования элементов в объекте типа vector<int>. Например,
    вектор 1, 3, 5, 7, 9 становится вектором 9, 7, 5, 3, 1. Первая функция, изменяющая порядок следования
    элементов на противоположный, должна создавать новый объект класса vector, а исходный объект класса
    vector должен оставаться неизменным. Другая функция должна изменять порядок следования элементов
    в передаваемом ей векторе без использования других векторов. Указание: воспользуйтесь функцией swap.
*/

#include <iostream>
#include <string>
#include <vector>

void Print(std::string str, const std::vector<int>& vec)
{
    std::cout << str << ": ";
    for (int elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

std::vector<int> BadReverse(std::vector<int> myVector)
{
    std::vector<int> newVector(myVector.size());
    for (int i = 0; i < newVector.size(); ++i)
    {
        newVector[i] = myVector[myVector.size() - 1 - i];
    }
    return newVector;
}

void GoodReverse(std::vector<int>& myVector)
{
    for (int i = 0; i < myVector.size() / 2; ++i)
    {
        std::swap(myVector[i], myVector[myVector.size() - 1 - i]);
    }
}

int main()
{
    std::vector<int> myVec1 {1, 3, 5, 7, 9};
    std::vector<int> myVec1BadReverse = BadReverse(myVec1);
    std::cout << "Операции с myVec1:\n";
    Print("Reverse с помощью BadReverse", myVec1BadReverse);
    GoodReverse(myVec1);
    Print("Reverse с помощью GoodReverse", myVec1);
    
    std::vector<int> myVec2 {11, 13, 15, 17, 19, 21};
    std::vector<int> myVec2BadReverse = BadReverse(myVec2);
    std::cout << "Операции с myVec2:\n";
    Print("Reverse с помощью BadReverse", myVec2BadReverse);
    GoodReverse(myVec2);
    Print("Reverse с помощью GoodReverse", myVec2);
    return 0;
}
