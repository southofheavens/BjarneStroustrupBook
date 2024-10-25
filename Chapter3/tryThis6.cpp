/*
 * Выполните эту программу, вводя разные значения. Попробуйте ввести небольшие значения (например, 2 и 3);
 * большие значения (больше, чем 127; больше, чем 1000); отрицательные значения; испытайте числа 56, 89, 128;
 * нецелые числа (например, 56.9 и 56.2). Кроме результатов преобразования типа double в тип int и типа int
 * в тип char на вашем компьютере, эта программа показывает, какой символ (если таковой имеется) выводится
 * для заданного целого числа.
 */

#include <iostream>

int main()
{
    double d = 0;
    while (std::cin>>d)
    {
        int i = d;
        char c = i;
        int i2 = c;
        std::cout << " d==" << d
            << " i==" << i
            << " i2==" << i2
            << " char(" << c << ")\n";
    }
    return 0;
}
