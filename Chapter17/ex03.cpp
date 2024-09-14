/*
    Напишите функцию void to_lower(char* s), заменяющую все прописные символы в C-строке s их строчными
    эквивалентами. Например, строка "Hello, World!" должна принять вид "hello, world!". Не используйте
    стандартные библиотечные функции. C-строка представляет собой массив символов, который завершается
    нулем, поэтому если вы обнаружите символ 0, то это значит, что вы находитесь в конце массива.
*/

#include <iostream>

void ToLower(char* s)
{
    for(unsigned int i = 0; s[i]; ++i)
    {
        if (65 <= (int)s[i] && (int)s[i] <= 90)
        {
            s[i] = char((int)s[i] + 32);
        }
    }
}

int main()
{
    char s[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0};
    std::cout << s << '\n';
    ToLower(s);
    std::cout << s << '\n';
    return 0;
}