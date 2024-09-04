/*
    Перепишите все функции из раздела 18.7, используя для сравнения обращенную копию строки; например,
    введите строку "home", из нее сгенерируйте строку "emoh" и сравните эти две строки, чтобы убедиться,
    что слово home - не палиндром.
 
    Не особо понял суть задания, но да ладно.
*/

#include <iostream>
#include <string>

// Палиндромы с использованием string
bool IsPalindrome(const std::string& s)
{
    int first = 0;
    int last = (int)s.length() - 1;
    while (first < last)
    {
        if (s[first] != s[last]) {
            return false;
        }
        ++first;
        --last;
    }
    return true;
}

// Палиндромы с использованием массивов
bool IsPalindrome(const char s[], int n)
    // s указывает на первый символ массива из n символов
{
    int first = 0;
    int last = n - 1;
    while (first < last)
    {
        if (s[first] != s[last]) {
            return false;
        }
        ++first;
        --last;
    }
    return true;
}

// Палиндромы с использованием указателей (рекурсивная)
bool IsPalindrome(const char* first, const char* last)
    // Указатель first указывает на первую букву
    // Указатель last указывает на последнюю букву
{
    while (first < last)
    {
        if (*first != *last) {
            return false;
        }
        return IsPalindrome(first+1,last-1);
    }
    return true;
}

// Палиндромы с использованием обращенной копии строки
std::string ReverseString(const std::string& s)
{
    std::string result;
    for (int i = int(s.length()) - 1; i >= 0; --i) {
        result += s[i];
    }
    return result;
}

int main()
{
    // Палиндромы с использованием string
    std::string pal1 = "radar";
    std::cout << pal1 << " is ";
    IsPalindrome(pal1) ? std::cout << "" : std::cout << "not ";
    std::cout << "palindrome\n";
    
    // Палиндромы с использованием массивов
    char pal2[6] = {'r','a','d','a','r',0};
    std::cout << pal2 << " is ";
    IsPalindrome(pal2,(int)strlen(pal2)) ? std::cout << "" : std::cout << "not ";
    std::cout << "palindrome\n";
    
    // Палиндромы с использованием указателей (рекурсивная)
    std::cout << pal2 << " is ";
    IsPalindrome(&pal2[0],&pal2[strlen(pal2)-1]) ? std::cout << "" : std::cout << "not ";
    std::cout << "palindrome\n";
    
    // Палиндромы с использованием обращенной копии строки
    std::cout << pal1 << " is ";
    ReverseString(pal1) == pal1 ? std::cout << "" : std::cout << "not ";
    std::cout << "palindrome\n";
    
    return 0;
}
