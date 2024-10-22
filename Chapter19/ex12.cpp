/*
    Определите класс File_handle, конструктор которого получает аргумент типа string (имя файла) и открывает
    файл, а деструктор закрывает этот файл.
*/

#include <iostream>
#include <string>
#include <fstream>

class FileHandle
{
public:
    FileHandle(const std::string& filename)
    {
        fst.open(filename);
    }
    
    ~FileHandle()
    {
        fst.close();
    }
    
private:
    std::fstream fst;
};

int main()
{
    FileHandle some("SomeFile.txt");
    return 0;
}
