/*
    Напишите варианты функций из упражнения 5 для класса vector<string>.
*/

#include <iostream>
#include <string>
#include <vector>

void Print(std::string str, const std::vector<std::string>& vec)
{
    std::cout << str << ": ";
    for (std::string elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << '\n';
}

std::vector<std::string> BadReverse(std::vector<std::string> myVector)
{
    std::vector<std::string> newVector(myVector.size());
    for (int i = 0; i < newVector.size(); ++i)
    {
        newVector[i] = myVector[myVector.size() - 1 - i];
    }
    return newVector;
}

void GoodReverse(std::vector<std::string>& myVector)
{
    for (int i = 0; i < myVector.size() / 2; ++i)
    {
        std::swap(myVector[i], myVector[myVector.size() - 1 - i]);
    }
}

int main()
{
    std::vector<std::string> myVec1 {"a", "c", "y", "o", "z"};
    std::vector<std::string> myVec1BadReverse = BadReverse(myVec1);
    std::cout << "Операции с myVec1:\n";
    Print("Reverse с помощью BadReverse", myVec1BadReverse);
    GoodReverse(myVec1);
    Print("Reverse с помощью GoodReverse", myVec1);
    
    std::vector<std::string> myVec2 {"Obama", "Tramp", "Putin", "America", "Russia", "China"};
    std::vector<std::string> myVec2BadReverse = BadReverse(myVec2);
    std::cout << "Операции с myVec2:\n";
    Print("Reverse с помощью BadReverse", myVec2BadReverse);
    GoodReverse(myVec2);
    Print("Reverse с помощью GoodReverse", myVec2);
    return 0;
}
