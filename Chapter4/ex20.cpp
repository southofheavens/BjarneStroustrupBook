/*
 * Измените программу из упр. 19 так, чтобы при вводе имени она выводила соответствующее количество
 * баллов или сообщение "Имя не найдено".
 * 
 * How to compile:
 * clang++ -std=c++14 ex20.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> names;
    std::vector<int> scores;
    std::string name;
    int score;
    while(name != "NoName" || score != 0)
    {
        std::cin >> name;
        std::cin >> score;
        if (name != "NoName" || score != 0)
        {
            names.push_back(name);
            scores.push_back(score);
        }
    }
    std::vector<std::string> checkNames = names;
    sort(checkNames.begin(), checkNames.end());
    bool anyRepeats = false;
    for (int i = 0; i < checkNames.size() - 1; ++i)
    {
        if (checkNames[i] == checkNames[i + 1]) {
            anyRepeats = true;
        }
    }
    std::cout << "---\n";
    if(anyRepeats) {
        std::cout << "Каждое имя должно быть единственным!\n";
    }
    else
    {
        std::cout << "Введите имя, для которого вы хотите узнать количество баллов: ";
        std::string name;
        std::cin >> name;
        for (int i = 0; i < names.size(); ++i)
        {
            if (name == names[i])
            {
                std::cout << scores[i] << '\n';
                break;
            }
            else if (i == names.size() - 1) {
                std::cout << "Имя не найдено\n";
            }
        }
    }
    return 0;
}
