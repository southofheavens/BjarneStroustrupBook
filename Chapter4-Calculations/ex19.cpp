/*
    Напишите программу, в которую сначала вводится набор пар, состоящих из имени и значения, например
    Joe 17 и Barbara 22. Для каждой пары занесите имя в вектор names, а число - в вектор scores (в 
    соответствующие позиции, так что если names[7]=="Joe", то scores[7]==17). Прекратите ввод, встретив
    строку ввода NoName 0. Убедитесь, что каждое имя единственное, и выведите сообщение об ошибке, если
    имеется имя, введенное дважды. Выведите на печать все пары(имя, баллы) по одной в строке.
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
        for (int i = 0; i < names.size(); ++i)
        {
            std::cout << names[i] << ' ' << scores[i] << '\n';
        }
    }
    return 0;
}
