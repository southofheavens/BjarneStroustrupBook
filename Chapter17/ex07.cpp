/*
    Напишите программу, считывающую символы из потока cin в массив, выделенный в динамической памяти.
    Читайте отдельные символы, пока не встретится восклицательный знак (!). Не используйте класс
    std::string и не беспокойтесь об исчерпании памяти.
*/

#include <iostream>

char* AddLetter(char* arr, char letter)
{
    if (arr)
    {
        unsigned int sizeOfArr = 0;
        for(int i = 0; arr[i]; ++i) {
            sizeOfArr++;
        }

        char* newArr = new char[sizeOfArr + 1];
        for(int i = 0; arr[i]; ++i){
            newArr[i] = arr[i];
        }
        newArr[sizeOfArr] = letter;
        delete[] arr;
        return newArr;
    }
    char* newArr = new char[1]{letter};
    return newArr;
}

int main()
{
    char* arr = nullptr;
    char ch;
    while(std::cin.get(ch) && ch != '!')
    {
        arr = AddLetter(arr,ch);
    }
    std::cout << arr << '\n';
    delete[] arr;
    return 0;
}
