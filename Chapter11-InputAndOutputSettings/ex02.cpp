/*
    Напишите программу, которая для данного имени файла и слова выводит все строки файла, содержащие
    это слово, вместе с номерами строк. Указание: getline().
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream ifs;
    ifs.open("file1"); // Файл, в котором ищем слово
    std::string searchWord = "cat"; // Слово, которое мы ищем
    
    std::string string;
    int counter = 1;
    std::string suspect;
    while(getline(ifs, string))
    {
        std::istringstream ss(string);
        while(ss >> suspect)
        {
            if (suspect == searchWord)
            {
                std::cout << "Номер строки: " << counter << ", строка: " << string << '\n';
                break;
            }
        }
        counter++;
    }
    ifs.close();
    return 0;
}
