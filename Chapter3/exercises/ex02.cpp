/*
 * Напишите на языке C++ программу, которая преобразует мили в километры. Ваша программа должна 
 * содержать понятное приглашение пользователю ввести количество миль. Указание: в одной миле 1.609 км.
 */

#include <iostream> 

int main()
{
    std::cout << "Введите количество миль: ";
    double miles;
    std::cin >> miles;
    std::cout << "В " << miles << " милях " << miles * 1.609 << " километров.\n";
    return 0;
}