/*
    Измените программу из предыдущего упражнения так, чтобы в нее вводилось число max, а затем найдите
    все простые числа от 1 до max.
*/

#include <iostream>
#include <vector>

bool isPrime(int number)
{
    bool result;
    int countOfDivisors = 0;
    for (int i = 1; i <= number; ++i)
    {
        if (number % i == 0)
        {
            countOfDivisors++;
        }
    }
    countOfDivisors == 2 ? result = true : result = false;
    return result;
}

int main()
{
    int max;
    std::cin >> max;
    std::vector<int> primeNums;
    for (int i = 1; i <= max; ++i)
    {
        if (isPrime(i))
        {
            primeNums.push_back(i);
        }
    }
    for (int num : primeNums)
    {
        std::cout << num << '\n';
    }
    return 0;
}
