/*
    Несколько заданий, касающихся контейнера vector.
 
    1. Прочитайте несколько чисел с плавающей точкой (не меньше 16 значений) из файла в контейнер
    vector<double> с именем vd.
    2. Выведите элементы контейнера vd в поток cout.
    3. Создайте вектор vi типа vector<int> с таким же количеством элементов, что и в контейнере vd;
    скопируйте элементы из контейнера vd в контейнер vi.
    4. Выведите в поток cout пары (vd[i],vi[i]) по одной в строке.
    5. Выведите на экран сумму элементов контейнера vd.
    6. Выведите на экран разность сумм элементов контейнеров vd и vi.
    7. Существует стандартный алгоритм reverse, получающий в качестве аргументов последовательность
    (пару итераторов); поменяйте порядок следования элементов vd на противоположный и выведите элементы
    vd в поток cout.
    8. Вычислите среднее значение элементов в контейнере vd и выведите его на экран.
    9. Создайте новый контейнер vector<double> с именем vd2 и скопируйте в него элементы контейнера
    vd, которые меньше среднего значения.
    10. Отсортируйте контейнер vd и выведите его элементы на экран.
 
    data.txt:
    16.6 15.0 13.3 -59.61 17.17 14.89 900 19.5 -741.9 18 14.4 1945 30.04 28.4 55.2 123.321
*/

#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<double> vd;
    std::ifstream ifs{"data.txt"};
    
    for (double el; ifs >> el;) {
        vd.push_back(el);
    }
    
    for (double el : vd) {
        std::cout << el << ' ';
    }
    std::cout << '\n' << '\n';
    
    // ---------------
    
    std::vector<int> vi(vd.size());
    for (int i = 0; i < vd.size(); ++i) {
        vi[i] = vd[i];
    }
    
    // ---------------
    
    for (int i = 0; i < vd.size(); ++i) {
        std::cout << '(' << vd[i] << ',' << vi[i] << ')' << '\n';
    }
    
    double vdSum = 0;
    vdSum = std::accumulate(vd.begin(), vd.end(), vdSum);
    std::cout << "\nСумма элементов контейнера vd: " << vdSum << '\n';
    int viSum = 0;
    viSum = std::accumulate(vi.begin(), vi.end(), viSum);
    std::cout << "\nРазность сумм элементов контейнеров vd и vi: " << vdSum - viSum << '\n';
    
    // ---------------
    
    std::reverse(vd.begin(), vd.end());
    std::cout << "\nstd::reverse(vd.begin(),vd.end()):\n";
    for (double el : vd) {
        std::cout << el << ' ';
    }
    
    // ---------------
    
    double vdAverage = 0;
    vdAverage = std::accumulate(vd.begin(), vd.end(), vdAverage);
    vdAverage /= vd.size();
    std::cout << "\n\nСреднее значение элементов в контейнере vd: " << vdAverage << '\n';
    
    // ---------------
    
    std::vector<double> vd2(vd.size());
    std::copy_if(vd.begin(),vd.end(),vd2.begin(),[vdAverage](double elem){return elem < vdAverage;});
    std::cout << "\nЭлементы контейнера vd, которые меньше среднего значения:\n";
    for (double el : vd2) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    
    // ---------------
    
    std::cout << "\nstd::sort(vd.begin(),vd.end()):\n";
    std::sort(vd.begin(),vd.end());
    for (double el : vd) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
    
    ifs.close();
    return 0;
}
