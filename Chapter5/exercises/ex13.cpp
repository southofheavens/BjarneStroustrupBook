/*
 * Следующая программа довольно сложная. Создайте вариант, в котором игрок может играть постонно (без
 * остановки и повторного запуска) и в каждой новой игре генерируются новые четыре цифры. Четыре
 * случайные цифры можно сгенерировать с помощью четырех вызовов генератора случайных чисел randint(10)
 * из заголовочного файла std_lib_facilities.h. Обратите внимание на то, что при повторном выполнении
 * программы вы каждый раз будете получать одинаковые последовательности из четырех цифр. Для того чтобы 
 * избежать этого, предложите пользователю ввести любое число и до вызова функции randint(10) вызовите
 * функцию srand(n), где n - число, введенное пользователем. Такое число n называется начальным значением
 * (seed), причем разные начальные значения приводят к разным последовательностям случайных чисел.
 *
 * How to compile:
 * clang++ -std=c++14 ex13.cpp
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
            std::cout << "Поздравляю! Вы угадали число! Хотите сыграть ещё раз?\n";
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
                std::cout << "Отлично! Программа загадала новое четырехзначное число, попробуйте угадать его!\n";
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
