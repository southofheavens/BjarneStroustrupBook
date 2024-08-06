/*
    В заданиях вам было предложено написать программу, которая для определенного ряда чисел определяла
    бы наибольшее и наименьшее числа в нем. Число, которое повторяется в последовательности наибольшее
    количество раз, называется модой. Напишите программу, определяющую моду множества положительных
    чисел.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {5, 4, 8, 14, 8, 1, 2, 3, 4, 7, 4, 21, 78, 43, 21, 54, 21, -150, 21};

    int maxCoincidences = 0;
    int coincidences = 0;
    
    sort(numbers.begin(), numbers.end());
    int moda = numbers[0];
    for(int i = 0; i < numbers.size() - 1; ++i)
    {
        if (numbers[i] == numbers[i + 1])
        {
            coincidences++;
        }
        else
        {
            if (coincidences != 0 && coincidences > maxCoincidences)
            {
                moda = numbers[i];
                maxCoincidences = coincidences;
            }
            coincidences = 0;
        } 
    }
    std::cout << moda;
    return 0;
}
