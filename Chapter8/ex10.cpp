/*
    Напишите функцию, которая находит наименьший и наибольший элементы вектора, являющегося ее аргументом,
    а также вычисляющую их среднее и медиану. Не используйте глобальные переменные. Результаты можно
    вернуть либо в виде структуры struct, либо с помощью механизма передаачи аргументов по ссылке.
    Какой из этих двух способов следует предпочесть и почему?
*/

#include <iostream>
#include <vector>

struct VectorInfo
{
    double minElem;
    double maxElem;
    double averageValue;
    double median;
};

VectorInfo VectorSearch(std::vector<double> myVector)
{
    VectorInfo info;
    sort(myVector.begin(), myVector.end());
    
    info.minElem = myVector[0];
    info.maxElem = myVector[myVector.size() - 1];
    
    double sum = 0;
    for (double elem : myVector)
    {
        sum += elem;
    }
    info.averageValue = sum / myVector.size();
    
    if (myVector.size() % 2 != 0)
    {
        info.median = myVector[myVector.size() / 2];
    }
    else
    {
        info.median = (myVector[myVector.size() / 2 - 1] + myVector[myVector.size() / 2]) / 2;
    }
    return info;
}

int main()
{
    std::vector<double> myVector {19, -7, 14, 150, 22, 11, 0, -41, -543, 1024};
    VectorInfo info = VectorSearch(myVector);
    std::cout << info.minElem << " " << info.maxElem << " ";
    std::cout << info.averageValue << " " << info.median << '\n';
    return 0;
}
