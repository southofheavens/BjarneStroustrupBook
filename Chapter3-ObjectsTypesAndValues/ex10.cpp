/*
    Напишите программу, принимающую на входе символ операции с двумя операндами и выводящую на экран
    результат вычисления. Например:
    + 100 3.14
    * 4 5
    Считайте символ операции в строку с именем operation и, используя инструкцию if, выясните, какую
    операцию хочет выполнить пользователь, например if (operatoin=="+"). Считывайте операнды в 
    переменные типа double. Выполните операции +, -, *, /, plus, minus, mul и div, имеющие очевидный
    смысл.
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Введите через пробел желаемую операцию и два операнда: ";
    std::string operation;
    double var1;
    double var2;
    std::cin >> operation >> var1 >> var2;
    if (operation == "+" || operation == "plus")
    {
        std::cout << var1 << ' ' << operation << ' ' << var2 << " = " << var1 + var2 << '\n';
    }
    else if (operation == "-" || operation == "minus")
    {
        std::cout << var1 << ' ' << operation << ' ' << var2 << " = " << var1 - var2 << '\n';
    }
    else if (operation == "*" || operation == "mul")
    {
        std::cout << var1 << ' ' << operation << ' ' << var2 << " = " << var1 * var2 << '\n';
    }
    else if (operation == "/" || operation == "div")
    {
        if (var2 == 0)
        {
            std::cout << "Деление на ноль запрещено!\n";
        }
        else
        {
            std::cout << var1 << ' ' << operation << ' ' << var2 << " = " << var1 / var2 << '\n';
        }
    }
    else
    {
        std::cout << "Неизвестная операция.\n";
    }
    return 0;
}
