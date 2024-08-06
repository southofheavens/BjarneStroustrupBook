/*
    Напишите программу, удаляющую из файла все гласные буквы. Например, фраза Once upon a time! принимает
    вид nc pn tm!. Удивительно часто результат остается вполне удобочитаемым; проверьте это на своих друзьях.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::fstream iofs;
    iofs.open("file1", std::ios_base::in); // Открываем файл для чтения
    char ch;
    std::stringstream ss;
    while(iofs.get(ch))
    {
        if (ch != 'e' && ch != 'u' && ch != 'i' && ch != 'o' && ch != 'a'
            && ch != 'E' && ch != 'U' && ch != 'I' && ch != 'O' && ch != 'A')
        {
            ss << ch;
        }
    }
    iofs.close(); // Закрываем файл
    // Открываем файл для записи и при этом обрезаем его до нулевой длины
    iofs.open("file1", std::ios_base::trunc | std::ios_base::out);
    while(ss.get(ch))
    {
        iofs << ch;
    }
    iofs.close(); // Закрываем файл
    return 0;
}
