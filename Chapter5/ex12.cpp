/*
    Реализуйте простую игру на угадывание "Быки и коровы". Программа должна хранить вектор из четырех
    различных чисел в диапазоне от 0 до 9 (т.е., например, 2345, не не 4455), а пользователь должен
    угадать загаданное число. Допустим, программа загадала число 1234, а пользователь назвал число 1359;
    программа должна ответить "1 бык и 1 корова", поскольку пользователь угадал одну правильную цифру (1)
    в правильной позиции (бык) и одну правильную цифру (3) в неправильной позиции (корова). Угадывание
    продолжается, пока пользователь не получит четырех быков, т.е. не угадает четыре правильные цифры
    в четырех правильных позициях.
*/

#include <iostream>
#include <vector>
#include <ctime> // Данная библиотека нужна для вызова функции time()
#include <cstdlib> // Данная библиотека нужна для вызова функций rand() и srand()

std::vector<int> GenerateBullsAndCows()
{
    int num1 = rand() % 10, num2, num3, num4;
    std::vector<int> bullsAndCows = {num1};
    num2 = rand() % 10;
    while (num1 == num2)
    {
        num2 = rand() % 10;
    }
    bullsAndCows.push_back(num2);
    num3 = rand() % 10;
    while (num3 == num1 || num3 == num2)
    {
        num3 = rand() % 10;
    }
    bullsAndCows.push_back(num3);
    num4 = rand() % 10;
    while (num4 == num1 || num4 == num2 || num4 == num3)
    {
        num4 = rand() % 10;
    }
    bullsAndCows.push_back(num4);
    return bullsAndCows;
}

int main()
{
    srand((int)time(NULL)); // Используется в C и C++ для инициализации генератора случайных чисел
    /*
    Важно: Если вы не вызываете `srand((int)time(NULL))`, генератор случайных чисел будет использовать
    одно и то же "семя" при каждом запуске программы, что приведет к получению одинаковой
    последовательности "случайных" чисел.
    */
    std::vector<int> bullsAndCows = GenerateBullsAndCows();
    std::cout << "Программа загадала четырехзначное число, попробуйте угадать!\n";
    std::cout << '\n';
    bool final = false;
    while (!final)
    {
        std::cout << "Введите ваше число: ";
        int userNumber;
        std::cin >> userNumber;
        int num1 = userNumber / 1000;
        int num2 = userNumber % 1000 / 100;
        int num3 = userNumber % 100 / 10;
        int num4 = userNumber % 10;
        std::vector<int> vecUserNumber = {num1, num2, num3, num4};

        // правильная цифра в правильной позиции - бык, правильная цифра в неправильной позиции - корова
        int countOfBulls = 0;
        int countOfCows = 0;
        for (int i = 0; i < vecUserNumber.size(); ++i)
        {
            for (int j = 0; j < bullsAndCows.size(); ++j)
            {
                if (vecUserNumber[i] == bullsAndCows[j])
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
            std::cout << "Поздравляю! Вы угадали число!\n";
            final = true;
        }
    }
    return 0;
}
