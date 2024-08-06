/*
    Создайте вектор чисел Фибоначчи и выведите их на печать с помощью функции из упр. 2. Для того чтобы
    создать вектор, напишите функцию fibonacci(x,y,v,n), в которой аргументы x и y имеют тип int, 
    аргумент v представляет собой пустой vector<int>, а аргумент n - количество элементов, подлежащих
    записи в вектор v; элемент v[0] будет равен x, а v[1] - y. Число Фибоначчи - это элемент 
    последовательности, в которой каждый элемент является суммой двух предыдущих. Например, если 
    последовательность начинается с чисел 1 и 2, то мы получаем последовательность 1, 2, 3, 5, 8, 13,
    21, ... . Функция fibonacci() должна генерировать такую последовательность, начинающуюся с чисел x и y.
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
    Fibonacci(5, 8, emptyVector, 10);
    Print("Вектор с числами Фибоначчи", emptyVector);
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
}
