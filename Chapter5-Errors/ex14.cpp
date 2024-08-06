/*
    Введите пары (день недели, значение) из стандартного потока ввода. Например:
    Tuesday 23 Friday 56 Tuesday -3 Thursday 99
    Запишите все значения для каждого дня недели в вектор vector<int>. Выведите значения семи векторов
    для каждого из дней недели. Напечатайте сумму чисел в каждом из векторов. Неправильный день недели,
    например Funday, можно игнорировать, но обычные синонимы допускаются, например Mon и monday.
    Выведите на печать количество отвергнутых значений.
*/

#include <iostream>
#include <string>
#include <vector>

std::string ToLowerCase(std::string word) // Функция, которая переводит слово в нижний регистр
{
    std::string result;
    for (int i = 0; i < word.length(); ++i)
    {
        result += tolower(word[i]);
    }
    return result;
}

int main()
{
    std::vector<std::vector<int> > daysOfWeek(7);
    std::vector<std::string> namesOfDays = {"mon", "tue", "wed", "thu", "fri", "sat", "sun"};
    int countOfWrongs = 0;
    std::string dayOfWeek;
    int value;
    std::cin >> dayOfWeek >> value;
    while(std::cin)
    {
        dayOfWeek = ToLowerCase(dayOfWeek.substr(0, 3)); // Передаем в функцию первые три буквы введённого слова
        for (int i = 0; i < namesOfDays.size(); ++i)
        {
            if (dayOfWeek == namesOfDays[i])
            {
                daysOfWeek[i].push_back(value);
                break;
            }
            else if (i == namesOfDays.size() - 1)
            {
                countOfWrongs++;
            }
        }
        std::cin >> dayOfWeek >> value;
    }
    int sum = 0;
    for (int i = 0; i < daysOfWeek.size(); ++i)
    {
        std::cout << namesOfDays[i] << ": ";
        for (int value : daysOfWeek[i])
        {
            sum += value;
        }
        std::cout << sum << '\n';
        sum = 0;
    }
    std::cout << "Количество отвергнутых значений: " << countOfWrongs << '\n';
    return 0;
}
