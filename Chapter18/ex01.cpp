/*
    Напишите функцию char*strdup(const char*), копирующую C-строку в динамическую память, которую она
    выделяет для этой копии строки. Не используйте никаких стандартных функций. Не используйте
    индексирование, вместо него применяйте оператор разыменования *.
*/

#include <iostream>

char* StrDup(const char* s)
{
    unsigned int lenOfS = 0;        // Длина строки, переданной в качестве аргумента
    while(*s)
    {
        lenOfS++;
        ++s;
    }
    s -= lenOfS;                    // Возвращаем указатель в исходную позицию

    char* newS = new char[lenOfS];  // Выделяем память для новой строки
    for(unsigned int i = 0; i < lenOfS; ++i)
    {
        *newS++ = *s++;
    }
    return newS - lenOfS;
}

int main()
{
    char s[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0};
    char* newS = StrDup(s);
    std::cout << s << '\n';
    std::cout << newS << '\n';

    delete[] newS;
    return 0;
}
