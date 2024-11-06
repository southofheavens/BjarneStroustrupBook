/*
 * Напишите программу, "заглушающую" нежелательные слова; иначе говоря, считывайте слова из потока cin
 * и выводите их в поток cout, заменяя нежелательные слова словом BLEEP. Начните с одного нежелательного
 * слова, например
 * string disliked = "Broccoli";
 * Когда отладите программу, добавьте еще несколько нежелательных слов.
 * 
 * How to compile:
 * clang++ -std=c++14 tryThis6.cpp
 */

#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> words;
    std::vector<std::string> dislikedWords {"America", "Obama", "Fuhrer"};
    for (std::string word; std::cin >> word;)
    {
        bool find = false;
        for (int i = 0; i < dislikedWords.size(); ++i) 
        {
            if (word == dislikedWords[i]) {
                find = true;
            }
        }
        if (find == true) {
            words.push_back("BLEEP");
        }
        else {
            words.push_back(word);
        }
    }
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << '\n';
    }
    return 0;
}
