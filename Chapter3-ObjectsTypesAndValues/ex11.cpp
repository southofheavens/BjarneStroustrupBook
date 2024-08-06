/*
    Напишите программу, предлагающую пользователю ввести определенное количество 1-, 5-, 10-, 25- и
    50-центовых и долларовых монет. Пользователь должен по отдельности ввести количество монет
    каждого достоинства, например "Сколько у вас одноцентовых монет?". Затем программа должна вывести
    результат примерно такого вида.

    У вас 23 одноцентовых монет.
    У вас 17 пятицентовых монет.
    У вас 14 десятицентовых монет.
    У вас 7 двадцатипятицентовых монет.
    У вас 3 пятидесятицентовых монет.
    Общая стоимость монет равна 573 центам.

    Усовершенствуйте программу: если у пользователя только одна монета, выведите ответ в грамматически
    правильной форме. Например, "14 десятицентовых монет" и "1 одноцентовая монета" (а не "1 
    одноцентовых монет"). Кроме того, выведите результат в долларах и центах, т.е. 5 долларов 73 цента,
    а не 573 цента.
*/

#include <iostream>
#include <string>

int main()
{
    int cent1;
    int cent5;
    int cent10;
    int cent25;
    int cent50;
    std::cout << "Сколько у вас одноцентовых монет? ";
    std::cin >> cent1;
    std::cout << "Сколько у вас пятицентовых монет? ";
    std::cin >> cent5;
    std::cout << "Сколько у вас десятицентовых монет? ";
    std::cin >> cent10;
    std::cout << "Сколько у вас двадцатипятицентовых монет? ";
    std::cin >> cent25;
    std::cout << "Сколько у вас пятидесятицентовых монет? ";
    std::cin >> cent50;

    int all = cent1 + cent5 * 5 + cent10 * 10 + cent25 * 25 + cent50 * 50;
    
    if (cent1 > 0)
    {
        if (cent1 % 10 == 0 || cent1 % 10 == 5 || cent1 % 10 == 6 || cent1 % 10 == 7
        || cent1 % 10 == 8 || cent1 % 10 == 9)
        {
            std::cout << "У вас " << cent1 << " одноцентовых монет.\n";
        }
        else if (cent1 % 10 == 1)
        {
            std::cout << "У вас " << cent1 << " одноцентовая монета.\n";
        }
        else
        {
            std::cout << "У вас " << cent1 << " одноцентовых монеты.\n";
        }
    }
    if (cent5 > 0)
    {
        if (cent5 % 10 == 0 || cent5 % 10 == 5 || cent5 % 10 == 6 || cent5 % 10 == 7
        || cent5 % 10 == 8 || cent5 % 10 == 9)
        {
            std::cout << "У вас " << cent5 << " пятицентовых монет.\n";
        }
        else if (cent5 % 10 == 1)
        {
            std::cout << "У вас " << cent5 << " пятицентовая монета.\n";
        }
        else
        {
            std::cout << "У вас " << cent5 << " пятицентовых монеты.\n";
        }
    }
    if (cent10 > 0)
    {
        if (cent10 % 10 == 0 || cent10 % 10 == 5 || cent10 % 10 == 6 || cent10 % 10 == 7
        || cent10 % 10 == 8 || cent10 % 10 == 9)
        {
            std::cout << "У вас " << cent10 << " десятицентовых монет.\n";
        }
        else if (cent10 % 10 == 1)
        {
            std::cout << "У вас " << cent10 << " десятицентовая монета.\n";
        }
        else
        {
            std::cout << "У вас " << cent10 << " десятицентовых монеты.\n";
        }
    }
    if (cent25 > 0)
    {
        if (cent25 % 10 == 0 || cent25 % 10 == 5 || cent25 % 10 == 6 || cent25 % 10 == 7
        || cent25 % 10 == 8 || cent25 % 10 == 9)
        {
            std::cout << "У вас " << cent25 << " двадцатипятицентовых монет.\n";
        }
        else if (cent25 % 10 == 1)
        {
            std::cout << "У вас " << cent25 << " двадцатипятицентовая монета.\n";
        }
        else
        {
            std::cout << "У вас " << cent25 << " двадцатипятицентовых монеты.\n";
        }
    }
    if (cent50 > 0)
    {
        if (cent50 % 10 == 0 || cent50 % 10 == 5 || cent50 % 10 == 6 || cent50 % 10 == 7
        || cent50 % 10 == 8 || cent50 % 10 == 9)
        {
            std::cout << "У вас " << cent50 << " пятидесятицентовых монет.\n";
        }
        else if (cent50 % 10 == 1)
        {
            std::cout << "У вас " << cent50 << " пятидесятицентовая монета.\n";
        }
        else
        {
            std::cout << "У вас " << cent50 << " пятидесятицентовых монеты.\n";
        }
    }
    int dollars = all / 100;
    all -= dollars * 100;
    std::cout << "Общая стоимость монет равна " << dollars;
    if (dollars % 10 == 1)
    {
        std::cout << " доллару ";
    }
    else
    {
        std::cout << " долларам, ";
    }
    std::cout << all;
    if (all % 10 == 1)
    {
        std::cout << " центу.\n";
    }
    else
    {
        std::cout << " центам.\n";
    }
    return 0;
}
