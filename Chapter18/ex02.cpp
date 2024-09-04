/*
    Напишите функцию char*findx(const char*s, const char*x), находящую первое вхождение C-строки x
    в C-строку s. Не используйте никаких стандартных функций. Не используйте индексирование, вместо 
    него применяйте оператор разыменования.
*/

#include <iostream>

char* FindX(const char* s, const char* x)
{
    unsigned int xShift = 0;
    unsigned int sShift = 0;
    while(*s)
    {
        while(true)
        {
            if (!*x) {
                return const_cast<char*>(s);
            }
            else if (*x != *s)
            {
                x-=xShift;
                xShift=0;
                s-=sShift;
                sShift=0;
                break;
            }
            x++;
            xShift++;
            s++;
            sShift++;
        }
        s++;
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
