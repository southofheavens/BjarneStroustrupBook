/*
    Напишите функцию int strcmp(const char*s1, const char*s2), сравнивающую две C-строки. Если в
    лексикографическом порядке строка s1 меньше строки s2, функция должна возвращать отрицательное
    число, если строки совпадают - нуль, а если строка s1 больше строки s2 - положительное число.
    Не используйте никаких стандартных функций. Не используйте индексирование, вместо него
    применяйте оператор разыменования *.
*/

#include <iostream>

int StrCmp(const char* s1, const char* s2)
{
    while(true)
    {
        if (!*s1 && !*s2)
        {
            return 0;
        }
        else if (!*s1)
        {
            return -1;
        }
        else if (!*s2)
        {
            return 1;
        }

        if (*s1 < *s2)
        {
            return -1;
        }
        else if (*s1 > *s2)
        {
            return 1;
        }
        ++s1;
        ++s2;
    }
}

int main()
{
    std::cout << StrCmp("Obama","Baiden") << '\n';
    return 0;
}
