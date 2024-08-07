/*
    Прочтите последовательности чисел типа double в вектор. Будем считать, что каждое значение
    представляет собой расстояние между двумя городами, расположенными на определенном маршруте.
    Вычислите и выведите на печать наименьшее и наибольшее расстояния между двумя соседними
    городами. Найдите и выведите на печаь среднее расстояние между двумя соседними городами.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Введите последовательность расстояний: ";
    std::vector<double> distances;
    for (double distance; std::cin >> distance; )
    {
        distances.push_back(distance);
    }

    double sumOfDist = 0;
    for (double dist : distances)
    {
        sumOfDist += dist;
    }

    std::cout << "Общее расстояние: " << sumOfDist << '\n';
    sort(distances.begin(), distances.end());
    std::cout << "Наименьшее расстояние: " << distances[0] 
    << ", наибольшее расстояние: " << distances[distances.size() - 1] << '\n';

    std::cout << "Среднее расстояние между двумя соседними городами: " << sumOfDist / distances.size() << '\n';
    return 0;
}
