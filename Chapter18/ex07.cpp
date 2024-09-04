/*
    Напишите варианты функций cat_dot() из предыдущих упражнений, получающие в качестве аргументов
    C-строки и возвращающие C-строку, размещенную в динамической памяти. Не используйте никаких
    функций или типов из стандартной библиотеки. Протестируйте эти функции на нескольких строках.
    Убедитесь, что вся память, выделенная с помощью оператора new, освобождается с помощью оператора
    delete. Сравните усилия, затраченные вами на выполнение упр. 5 и упр. 6.
*/

#include <iostream>

char* CatDot1(const char* s1, const char* s2)
{
    unsigned int lengthOfs1 = 0;
    while(*s1)
    {
        lengthOfs1++;
        ++s1;
    }
    s1-=lengthOfs1;
    unsigned int lengthOfs2 = 0;
    while(*s2)
    {
        lengthOfs2++;
        ++s2;
    }
    s2-=lengthOfs2;

    char* result = new char[lengthOfs1 + lengthOfs2 + 1];
    while(*s1)
    {
        *result = *s1;
        ++result;
        ++s1;
    }
    *result = '.';
    ++result;
    while(*s2)
    {
        *result = *s2;
        ++result;
        ++s2;
    }
    result-=(lengthOfs1 + lengthOfs2 + 1);
    return result;
}

char* CatDot2(const char* s1, const char* s2, const char* sep)
{
    unsigned int lengthOfs1 = 0;
    while(*s1)
    {
        lengthOfs1++;
        ++s1;
    }
    s1-=lengthOfs1;
    unsigned int lengthOfs2 = 0;
    while(*s2)
    {
        lengthOfs2++;
        ++s2;
    }
    s2-=lengthOfs2;
    unsigned int lengthOfSep = 0;
    while(*sep)
    {
        lengthOfSep++;
        ++sep;
    }
    sep-=lengthOfSep;

    char* result = new char[lengthOfs1 + lengthOfs2 + lengthOfSep];
    while(*s1)
    {
        *result = *s1;
        ++result;
        ++s1;
    }
    while(*sep)
    {
        *result = *sep;
        ++result;
        ++sep;
    }
    while(*s2)
    {
        *result = *s2;
        ++result;
        ++s2;
    }
    result-=(lengthOfs1 + lengthOfs2 + lengthOfSep);
    return result;
}

int main()
{
    char* word1 = CatDot1("Нильс","Бор");
    std::cout << word1 << '\n';

    char* word2 = CatDot2("Хот","Дог","-");
    std::cout << word2 << '\n';

    delete[] word2;
    delete[] word1;
    return 0;
}
