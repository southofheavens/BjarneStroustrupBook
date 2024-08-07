/*
    Напишите программу, вычисляющую сумму всех целых чисел, записанных в файле и разделенных пробелами.

    Файл numbers.txt:
    1 2 3 4 5 6 7 8 9 10

    Результат работы программы: 55
*/

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs{"numbers.txt"};
    int sum = 0;
    for (int num; ifs >> num;)
    {
        sum += num;
    }
    std::cout << sum << '\n';
    return 0;
}
