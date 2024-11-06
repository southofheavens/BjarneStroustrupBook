/*
 * Напишите программу для игры "Камень, бумага, ножницы". Если вы не знаете правил этой игры,
 * попробуйте выяснить их у друзей или с помощью Google (поиск информации - обычное занятие
 * для программистов). Для решения поставленной задачи используйте инструкцию switch. Кроме
 * того, машина должна давать случайные ответы (т.е. выбирать камень, бумагу или ножницы
 * на следующем ходу случайным образом). Написать настоящий генератор случайных чисел прямо сейчас
 * вам будет довольно сложно, поэтому заранее заполните вектор последовательностью значений.
 * Если встроить этот вектор в программу, то она всегда будет играть в одну и ту же игру, поэтому
 * целесообразно позволить пользователю самому вводить некоторые значения. Попробуйте помешать
 * пользователю легко угадывать следующий ход машины.
 *
 * P.S. Лично я не вижу ничего сложного в том, чтобы написать настоящий генератор, а не
 * использовать заранее подготовленный вектор, поэтому я буду делать это упражнение с генератором.
 * 
 * How to compile:
 * clang++ -std=c++14 ex10.cpp
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime> // Данная библиотека нужна для вызова функции time()
#include <cstdlib> // Данная библиотека нужна для вызова функций rand() и srand()

int main()
{
    srand(static_cast<int>(time(NULL))); // Используется в C и C++ для инициализации генератора случайных чисел
    /*
    Важно: Если вы не вызываете `srand((int)time(NULL))`, генератор случайных чисел будет использовать
    одно и то же "семя" при каждом запуске программы, что приведет к получению одинаковой
    последовательности "случайных" чисел.
    */
    std::vector<std::string> moves = {"Камень", "Бумага", "Ножницы"};
    std::string myMove;
    int indexOfMyMove;
    int moveOfMachine;
    int resultOfRound; // 0 если ничья, 1 если победа пользователя и 2 если победа машины
    while(true)
    {
        std::cout << "Чтобы сделать ход, введите 'Камень', 'Бумага' или 'Ножницы': ";
        std::cin >> myMove;
        indexOfMyMove = -1;
        for (int i = 0; i < moves.size(); ++i)
        {
            if (myMove == moves[i]) {
                indexOfMyMove = i;
            }
        }
        if (indexOfMyMove == -1) {
            std::cout << "Я не знаю, что такое " << myMove << "...\n";
            exit(1);
        }
        moveOfMachine = rand() % 3; // Генерирует значение от 0 до 2 (Камень, Бумага или Ножницы)
        std::cout << " Ваш ход     Ход компьютера " << '\n';
        std::cout << ' ' << moves[indexOfMyMove] << "     -     " << moves[moveOfMachine] << '\n';
        switch(indexOfMyMove)
        {
            case 0: // Ход пользователя - камень
                switch(moveOfMachine)
                {
                    case 0:
                        resultOfRound = 0;
                        break;
                    case 1:
                        resultOfRound = 2;
                        break;
                    case 2:
                        resultOfRound = 1;
                        break;
                }
                break;
            case 1: // Ход пользователя - бумага
                switch(moveOfMachine)
                {
                    case 0:
                        resultOfRound = 1;
                        break;
                    case 1:
                        resultOfRound = 0;
                        break;
                    case 2:
                        resultOfRound = 2;
                        break;
                }
                break;
            case 2: // Ход пользователя - ножницы
                switch(moveOfMachine)
                {
                    case 0:
                        resultOfRound = 2;
                        break;
                    case 1:
                        resultOfRound = 1;
                        break;
                    case 2:
                        resultOfRound = 0;
                        break;
                }
                break;
        }
        // Выводим результат раунда
        std::cout << "Результат раунда: ";
        if (resultOfRound == 0)
        {
            std::cout << "Ничья\n";
        }
        else if (resultOfRound == 1)
        {
            std::cout << "Победа пользователя\n";
            break;
        }
        else
        {
            std::cout << "Победа компьютера\n";
            break;
        }
    }
    return 0;
}
