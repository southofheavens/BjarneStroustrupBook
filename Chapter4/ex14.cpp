/*
    Измените программу, описанную в предыдущем упражнении, так, чтобы в нее вводилось число max, а затем
    найдите все простые числа от 1 до max.
*/  

#include <iostream>
#include <vector>

int main()
{
    int max;
    std::cin >> max;

    std::vector<int> numbers;
    for (int i = 0; i <= max; ++i)
    {
        numbers.push_back(i);
    }

    std::vector<int> primeNumbers;
    for (int i = 2; i <= max; ++i)
    {
        if (numbers[i] != 0)
        {
            primeNumbers.push_back(i);
            for (int j = i * i; j <= max; j += i)
            {
                numbers[j] = 0;
            }
        }
    }

    for (int number : primeNumbers)
    {
        std::cout << number << '\n';
    }
    return 0;
}
