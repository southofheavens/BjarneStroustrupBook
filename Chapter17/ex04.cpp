/*
    Напишите функцию char* strdup(const char*), копирующую C-строку в выделенную в динамической памяти
    строку. Не используйте стандартные библиотечные функции.
*/

#include <iostream>

char* StrDup(const char* s)
{
    unsigned int lenOfS = 0; // Длина строки, переданной в качестве аргумента
    for(unsigned int i = 0; s[i]; ++i)
    {
        lenOfS++;
    }

    char* newS = new char[lenOfS]; // Выделяем память для новой строки
    for(unsigned int i = 0; i < lenOfS; ++i)
    {
        newS[i] = s[i];
    }
    return newS;
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
