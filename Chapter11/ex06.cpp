/*
    Напишите программу, заменяющую знаки пунктуации пробелами. Считайте таковыми точку (.), точку с 
    запятой (;), запятую (,), вопросительный знак (?), дефис (-), одинарные кавычки ('). Не изменяйте
    символы, находящиеся между парами двойных кавычек ("). Например, строка " - don`t use the as-if
    rule." должна принять вид "   don t use the as if rule ".
*/

#include <iostream>
#include <string>

bool isPunctMark(char ch)
{
    if ((int)ch == 39 || ch == '.' || ch == ';' || ch == ',' || ch == '?' || ch == '-') 
    // (int)ch == 39, где ch равен одинарной кавычке
    {
        return true;
    }
    return false;
}

void removePunctMarks(std::string& string)
{
    for (int i = 0; i < string.length(); ++i)
    {
        if (isPunctMark(string[i]))
        {
            string[i] = ' ';
        }
    }
}

int main()
{
    std::cout << "Введите строку: ";
    std::string string;
    getline(std::cin, string);
    removePunctMarks(string);
    std::cout << "Результат работы функции removePunctMarks(): " << string << '\n';
    return 0;
}
