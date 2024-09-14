/*
    Напишите программу, вычисляющую сумму всех целых чисел, хранящихся в текстовом файле и разделенных
    пробелами и словами. Например, строка "bears: 17 elephants 9 end" дает результат, равный 26.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
    std::ifstream ifs{"result.txt", std::ios::in};
    
    std::vector<std::string> potentialNums;
    std::string potentialNum;
    while (ifs >> potentialNum) {
        potentialNums.push_back(potentialNum);
    }
    
    int sum = 0;
    for (int i = 0; i < potentialNums.size(); ++i)
    {
        std::stringstream ss{potentialNums[i]};
        int number;
        ss >> number;
        sum += number;
    }
    
    std::cout << sum << '\n';
    
    ifs.close();
    return 0;
}
