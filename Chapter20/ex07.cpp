/*
    Определите лексикографически последнюю строку в неупорядоченном классе vector<string>.
*/

#include <iostream>
#include <string>
#include "include/vector.h"

template<typename Iter>
Iter LexicLastString(Iter first, Iter last)
{
    Iter word = first;
    while (first != last)
    {
        if (*word < *first) {
            word = first;
        }
        ++first;
    }
    return word;
}

int main()
{
    vector<std::string> someWords {"Obama", "America", "Macron", "Fuhrer",
        "Zoo", "Dog", "Parrot", "BurgerKing", "Son"};
    std::cout << *LexicLastString(someWords.begin(), someWords.end()) << '\n';
    return 0;
}

