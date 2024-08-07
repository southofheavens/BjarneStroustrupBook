/*
    Напишите программу, читающую текстовый файл и записывающую его содержимое в новый файл в нижнем
    регистре.
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream ifs;
    ifs.open("file1", std::ios_base::in);
    
    std::ofstream ofs;
    ofs.open("file2", std::ios_base::out);
    
    char ch;
    while (ifs.get(ch))
    {
        ch = tolower(ch);
        ofs << ch;
    }
    
    ifs.close();
    ofs.close();
    return 0;
}
