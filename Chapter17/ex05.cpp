/*
    Напишите функцию char* findx(const char* s, const char* x), находящую первое вхождение C-строки x
    в строку s.
*/

#include <iostream>

char* FindX(const char* s, const char* x)
{
    for (int i = 0; s[i]; ++i)
    {
        for (int j = 0; ; ++j)
        {
            if (!x[j]) {
                return const_cast<char*>(&s[i]);
            } else if (x[j] != s[i + j]) {
                break;
            }
        }
    }
    return nullptr;
}

int main()
{
    char str[] = "Gute Wunshe, schnauzbartiher Hund !";
    char dog[] = {'H','u','n','d',0};
    char some[] = "Hauptsturmfuhrer";
    
    char* findDog = FindX(str,dog);
    char* findSome = FindX(str,some);
    
    std::cout << "Строка " << dog;
    if (!findDog) { std::cout << " не"; }
    std::cout << " найдена в строке " << str << '\n';
    
    std::cout << "Строка " << some;
    if (!findSome) { std::cout << " не"; }
    std::cout << " найдена в строке " << str << '\n';
    
    return 0;
}
