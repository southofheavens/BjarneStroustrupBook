/*
    Напишите программу, принимающую на вход два файла, содержащие лексикографически упорядоченные слова,
    разделенные пробелами, и объедините их, сохранив упорядочение.
 
    first.txt: apple key tobacco
    second.txt: america antony banana leg none
    result.txt: america antony apple banana key leg none tobacco
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Введите имя первого файла: ";
    std::string first;
    std::cin >> first;
    std::cout << "Введите имя второго файла: ";
    std::string second;
    std::cin >> second;
    
    std::fstream ifs1{first, std::ios::in};
    std::fstream ifs2{second, std::ios::in};
    std::fstream ofs{"result.txt", std::ios::out};
    
    std::vector<std::string> words;
    std::string word;
    while (ifs1 >> word) {
        words.push_back(word);
    }
    while (ifs2 >> word) {
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    for (std::string word : words) {
        ofs << word << ' ';
    }
    
    ofs.close();
    ifs2.close();
    ifs1.close();
    return 0;
}
