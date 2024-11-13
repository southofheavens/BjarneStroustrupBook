/*
 * Повторите упр. 12 из главы 5 (игра "Коровы и быки"), используя четыре буквы, а не четыре цифры.
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <string>

std::vector<char> GenerateBullsAndCows()
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    char let1 = alphabet[rand() % 26], let2, let3, let4;
    std::vector<char> bullsAndCows = {let1};
    let2 = alphabet[rand() % 26];
    while (let1 == let2)
    {
        let2 = alphabet[rand() % 26];
    }
    bullsAndCows.push_back(let2);
    let3 = alphabet[rand() % 26];
    while (let3 == let1 || let3 == let2)
    {
        let3 = alphabet[rand() % 26];
    }
    bullsAndCows.push_back(let3);
    let4 = alphabet[rand() % 26];
    while (let4 == let1 || let4 == let2 || let4 == let3)
    {
        let4 = alphabet[rand() % 26];
    }
    bullsAndCows.push_back(let4);
    return bullsAndCows;
}

int main()
{
    srand(time(NULL));
    std::vector<char> bullsAndCows = GenerateBullsAndCows();
    //std::cout << bullsAndCows[0] << bullsAndCows[1] << bullsAndCows[2] << bullsAndCows[3] << '\n';
    std::cout << "Программа загадала слово, состоящее из четырёх букв, попробуйте угадать!\n";
    bool final = false;
    while (!final)
    {
        std::cout << "Введите ваше слово: ";
        std::string userWord;
        std::cin >> userWord;
        char let1 = userWord[0], let2 = userWord[1], let3 = userWord[2], let4 = userWord[3];
        std::vector<char> vecUserWord = {let1, let2, let3, let4};

        // правильная цифра в правильной позиции - бык, правильная цифра в неправильной позиции - корова
        int countOfBulls = 0;
        int countOfCows = 0;
        for (int i = 0; i < vecUserWord.size(); ++i)
        {
            for (int j = 0; j < bullsAndCows.size(); ++j)
            {
                if (vecUserWord[i] == bullsAndCows[j])
                {
                    if (i == j)
                    {
                        countOfBulls++;
                    }
                    else
                    {
                        countOfCows++;
                    }
                }
            }
        }
        if (countOfBulls != 4)
        {
            std::cout << countOfBulls << " бык и " << countOfCows << " корова.\n";
        }
        else
        {
            std::cout << "Поздравляю! Вы угадали слово! Хотите сыграть ещё раз?\n";
            std::string answer;
            std::cin >> answer;
            while (answer != "Да" && answer != "Нет")
            {
                std::cout << "Я вас не понял... Введите, пожалуйста, 'Да' или 'Нет'\n";
                std::cin >> answer;
            }
            if (answer == "Да")
            {
                bullsAndCows = GenerateBullsAndCows();
                std::cout << "Отлично! Программа загадала новое слово, состоящее из четырёх букв, попробуйте угадать его!\n";
            }
            else if (answer == "Нет")
            {
                std::cout << "До свидания! :)\n";
                final = true;
            }
        }
    }
    return 0;
}
