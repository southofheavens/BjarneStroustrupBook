/*
 * Напишите программу, принимающую на вход число n и находящую первые n простых чисел.
 *
 * How to compile:
 * clang++ -std=c++14 ex15.cpp
 */

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> primeNumbers;
    int k = 1;
    int countOfDivisors;
    while (primeNumbers.size() < n)
    {
        countOfDivisors = 0;
        for (int i = 1; i <= k; ++i)
        {
            if (k % i == 0) {
                countOfDivisors++;
            }
        }
        if (countOfDivisors == 2) {
            primeNumbers.push_back(k);
        }
        k++;
    }

    for (int number : primeNumbers) {
        std::cout << number << '\n';
    }
    return 0;
}
