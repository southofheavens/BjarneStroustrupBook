/*
    Напишите программу, принимающую на вход имена двух файлов и создающую новый файл, в котором за содержимым
    первого файла следует содержимое второго; иначе говоря, программа должна конкатенировать два файла.
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "Введите имя первого файла: ";
    std::string file1;
    std::cin >> file1;
    std::cout << "Введите имя второго файла: ";
    std::string file2;
    std::cin >> file2;
    
    std::fstream ifs1{file1, std::ios::in};
    std::fstream ifs2{file2, std::ios::in};
    std::fstream ofs{"result", std::ios::out};
    
    std::string resultString;
    while(getline(ifs1, resultString)) {
        ofs << resultString << '\n';
    }
    while(getline(ifs2, resultString)) {
        ofs << resultString << '\n';
    }
    
    ofs.close();
    ifs2.close();
    ifs1.close();
    return 0;
}
