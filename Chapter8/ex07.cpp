/*
    Считайте пять имён в вектор vector<string> name, затем предложите пользователю указать возраст
    названных людей и запищите их в вектор vector<double> age. Затем выведите на печать пять пар
    (name[i], age[i]). Отсортируйте имена (sort(name.begin(), name.end())) и выведите на экран пары
    (name[i], age[i]). Сложность здесь заключается в том, чтобы получить вектор age, в котором 
    порядок следования элементов соответствовал бы порядку следования элементов вектора name. 
    Указание: перед сортировкой вектора name создайте его копию и используйте ее для получения 
    упорядоченного вектора age после сортировки вектора name. Затем выполните упражнение снова, разрешив
    использование произвольного количества имён.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "Введите имена через пробел ('СТОП' для окончания ввода): ";
    std::vector<std::string> names;
    std::string name;
    std::cin >> name;
    while(std::cin)
    {
        if (name == "СТОП") 
        {
            break;
        }
        names.push_back(name);
        std::cin >> name;
    }
    std::vector<std::string> copyNames = names;
    
    std::cout << "Теперь для каждого имени введите возраст этого человека (Ctrl + D для окончания ввода): ";
    std::vector<int> ages;
    for (int age; std::cin >> age;)
    {
        ages.push_back(age);
    }
    
    for (int i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << ' ' << ages[i] << '\n';
        if (i == names.size() - 1)
        {
            std::cout << "---\n";
        }
    }

    sort(names.begin(), names.end());
    for (std::string name : names)
    {
        for (int i = 0; i < copyNames.size(); ++i)
        {
            if (name == copyNames[i])
            {
                std::cout << name << " " << ages[i] << '\n';
            }
        }
    }
    return 0;
}
