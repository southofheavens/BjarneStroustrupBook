/*
    Измените программу из упр. 19 так, чтобы при вводе целого числа она выводила имена всех студентов,
    получивших указанное количество баллов, или сообщение "Баллы не найдены".
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
        if (checkNames[i] == checkNames[i + 1])
        {
            anyRepeats = true;
        }
    }
    std::cout << "---\n";
    if(anyRepeats)
    {
        std::cout << "Каждое имя должно быть единственным!\n";
    }
    else
    {
        std::cout << "Введите количество баллов, для которого вы хотите узнать студентов, получивших эти баллы: ";
        int score;
        std::cin >> score;
        bool anyStudent = false;
        for (int i = 0; i < scores.size(); ++i)
        {
            if (scores[i] == score)
            {
                std::cout << names[i] << '\n';
                anyStudent = true;
            }
        }
        if (!anyStudent)
        {
            std::cout << "Баллы не найдены\n";
        }
    }
    return 0;
}
