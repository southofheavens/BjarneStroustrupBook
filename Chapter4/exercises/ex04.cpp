/*
 * Напишите программу, угадывающую число. Пользователь должен задумать число от 1 до 100, а программа
 * должна задавать вопросы, чтобы выяснить, какое число он задумал (например, "Задуманное число
 * меньше 50"). Ваша программа должна уметь идентифицировать с помощью не более чем семи попыток.
 * Подсказка: используйте операторы < и <=, а также конструкцию if-else.
 * 
 * How to compile:
 * clang++ -std=c++14 ex04.cpp
 */

#include <iostream>

constexpr int ATTEMPS = 7;

int main()
{
    std::cout << "Привет! Загадай число, а я попытаюсь его отгадать.\n";
    std::cout << "Я буду выводить на экран предполагаемое число. У тебя есть три варианта ответа: ";
    std::cout << "'<', если загаданное число меньше предполагаемого числа, ";
    std::cout << "'>', если загаданное число больше предполагаемого числа и ";
    std::cout << "'=', если мне удалось отгадать число.\n";
    int left = 1; 
    int right = 100;
    char operation;
    for (int i = 0; i < ATTEMPS; ++i) // Бинарный поиск
    {
        int supposed = (left + right) / 2;
        std::cout << "Мне кажется, что загаданное вами число - " << supposed << '\n';
        std::cin >> operation;
        switch(operation)
        {
            case '<':
                right = (left + right) / 2 - 1;
                break;
            case '>':
                left = (left + right) / 2 + 1;
                break;
            case '=':
                std::cout << "Ура! У меня получилось угадать задуманное вами число!\n";
                return 0;
            default:
                std::cout << "Некорректный вариант ответа.\n";
                exit(1);
        }
    }
    std::cout << "К сожалению, у меня не получилось отгадать ваше число =(.\n";
    return 0;
}
