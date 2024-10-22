/*
    Определите операторы ввода и вывода (>> и <<) для класса vector.
*/

#include "include/vector.h"
#include <iostream>

int main()
{
    vector<int> arr;
    std::cin >> arr; // формат ввода - {elem1, elem2, elem3, ..., elemN}
    for (int elem : arr) {
        std::cout << elem << '\n';
    }
    return 0;
}
