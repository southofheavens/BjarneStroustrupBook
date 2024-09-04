/*
    Сколько байтов занимают типы int, double и bool? Ответьте на вопрос, не используя оператор sizeof,
    разве что для проверки вашего ответа. (Ответ: 4, 8 и 1)
*/

#include <iostream>

int main()
{
    std::cout << sizeof(int) << ' ' << sizeof(double) << ' ' << sizeof(bool) << '\n';
    return 0;
}
