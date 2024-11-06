/*
 * Выполните рассмотренную выше программу самостоятельно, записывая промежуточные результаты на лист бумаги.
 * Для проверки используйте фразу The cat cat jumped. Даже опытные программисты используют этот метод
 * для визуализации относительно неочевидных действий в небольших фрагментах кода.
 *
 * Входные данные / промежуточный результат / результат работы программы:
 * The cat cat jumped
 * Повторяющееся слово: cat
 * Program ended with exit code: 0
 */

#include <iostream>
#include <string>   // библиотека string для класса string

int main()
{
    std::string previous = " ";
    
    std::string current;
    while (std::cin>>current)   // CTRL+D для окончания ввода
    {
        if (previous == current) {
            std::cout << "Повторяющееся слово: " << current << '\n';
        }
        previous = current;
    }
    return 0;
}
