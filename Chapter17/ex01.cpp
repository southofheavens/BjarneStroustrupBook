/*
    Какой формат вывода значений указателей в вашей реализации языка? Указание: не читайте документацию.
*/

#include <iostream>

int main()
{
    int* variable = new int{5};
    std::cout << variable << '\n';
    return 0;
}

/*
    semyonzhuravlev@MacBook-Air Chapter17 % clang++ -std=c++11 ex01.cpp
    semyonzhuravlev@MacBook-Air Chapter17 % ./a.out
    0x600003d00020

    Исходя из результата работы программы, можно сделать вывод, что в используемой мною реализации языка 
    используется шестнадцатеричный формат вывода значений указателей.
*/
