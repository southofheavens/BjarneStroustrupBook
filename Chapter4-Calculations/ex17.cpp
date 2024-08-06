/*
    Напишите программу, определяющую наименьшее и наибольшее значениия, а также моду последовательности
    строк типа string.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> words;
    for(std::string word; std::cin >> word; )
    {
        words.push_back(word);
    }
    sort(words.begin(), words.end());
    std::string min = words[0];
    std::string max = words[words.size() - 1];
    std::string moda = words[0];

    int maxCoincidences = 0;
    int coincidences = 0;
    for(int i = 0; i < words.size() - 1; ++i)
    {
        if (words[i] == words[i + 1])
        {
            coincidences++;
        }
        else
        {
            if (coincidences != 0 && coincidences > maxCoincidences)
            {
                moda = words[i];
                maxCoincidences = coincidences;
            }
            coincidences = 0;
        } 
    }
    std::cout << "Наименьшее значение: " << min << '\n';
    std::cout << "Наибольшее значение: " << max << '\n';
    std::cout << "Мода: " << moda << '\n';
    return 0;
}
