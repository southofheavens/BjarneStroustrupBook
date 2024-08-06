/*
    Напишите функцию, которая для двух данных объектов типа vector<double>, price и weight, вычисляет
    значение, равное сумме всех произведений price[i]*weight[i]. Проверьте выполнение условия 
    weight.size() = price.size().
*/

#include <iostream>
#include <vector>

double Sum(std::vector<double>& price, std::vector<double>& weight)
{
    if (price.size() != weight.size())
    {
        throw std::invalid_argument("Массивы price и weight имеют разные размеры!");
    }
    double sum = 0;
    for (int i = 0; i < price.size(); ++i)
    {
        sum += price[i] * weight[i];
    }
    return sum;
}

int main()
try
{
    std::vector<double> price {500, 200, 600, 700};
    std::vector<double> weight {0.8, 1, 2, 1.5};
    double sum = Sum(price, weight);
    std::cout << sum << '\n';
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
}
