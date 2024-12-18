/*
 * 6. Теперь измените тело цикла так, чтобы он считывал только по одному числу типа double в каждой итерации.
 * Определите две переменные, чтобы отслеживать наименьшее и наибольшее среди всех ранее введенных значений.
 * В каждой итерации цикла выводите только что введенное число. Если оно окажется наименьшим среди всех
 * введенных, выводите на экран строку "Наименьшее среди введенных". Если же оно окажется наибольшим среди
 * введенных, выводите на экран строку "Наибольшее среди введенных".
 * 7. Добавьте к каждому введенному числу типа double единицу измерения; иначе говоря, вводите такие значения,
 * как 10cm, 2.5in, 5ft или 3.33m. Допустимыми являются четыре единицы измерения: cm, m, in, ft. Примите
 * следующие коэффициенты преобразования: 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Индикатор единицы измерения
 * вводите в строку. Можно считать ввод 12 m (с пробелом между числом и единицей измерения) эквивалентным
 * вводу 12m.
 * 8. Если введена неправильная единица измерения, например yard, meter, km или gallons, то такое значение
 * следует отклонить.
 * 9. Отслеживайте сумму введенных значений (помимо наименьшего и наибольшего) и их количество. Когда цикл
 * завершится, выведите на экран наименьшее введенное значение, наибольшее введенное знзачение, количество
 * введенных значений и их сумму. Обратите внимание на то, что, накапливая сумму, вы должны выбрать для нее
 * единицу измерения (используйте метры).
 * 10. Сохраняйте все введенные значения (преобразованные в метры) в векторе, а по завершении работы цикла
 * выведите их на экран.
 * 11. Перед тем как вывести значения из вектора, отсортируйте их в порядке возрастания.
 * 
 * How to compile:
 * clang++ -std=c++14 drill2.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    constexpr double CM_PER_M = 100;
    constexpr double CM_PER_IN = 2.54;
    constexpr double IN_PER_FT = 12;
   
    constexpr double CM_PER_FT = IN_PER_FT * CM_PER_IN;
    
    double min = INFINITY;
    double max = INFINITY;
    
    std::vector<double> values;
    double elem;
    double count = 0;
    double sum = 0;
    std::string measure;
    while (std::cin >> elem >> measure)
    {
        //std::cout << elem << ' ' << measure;
        if (measure == "cm") {
            // Всё норм
        }
        else if (measure == "m") {
            elem = elem * CM_PER_M;
        }
        else if (measure == "in") {
            elem = elem * CM_PER_IN;
        }
        else if (measure == "ft") {
            elem = elem * CM_PER_FT;
        }
        else
        {
            std::cout << "Я не знаю, что такое " << measure << "...\n";
            break;
        }
        count++;
        sum += elem;
        values.push_back(elem / 100);
        
        if (min == INFINITY && max == INFINITY) {
            min = max = elem;
        }
        else
        {
            if (elem > max) {
                max = elem;
            }
            else if (elem < min) {
                min = elem;
            }
        }
        std::cout << '\n';
    }
    
    std::sort(values.begin(), values.end());
    std::cout << "Введено значений: " << count << '\n';
    std::cout << "Введенные значения:\n";
    for (int i = 0; i < values.size(); ++i) {
        i != values.size() - 1 ? std::cout << values[i] << ' ' : std::cout << values[i] << '\n';
    }
    std::cout << "Наименьшее введенное значение (в метрах): " << min / 100 << '\n';
    std::cout << "Наибольшее введенное значение (в метрах): " << max / 100 << '\n';
    std::cout << "Сумма введённых значений (в метрах): " << sum / 100 << '\n';
    
    return 0;
}
