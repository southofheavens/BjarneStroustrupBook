/*
    Разработайте и реализуйте класс Name_pairs, содержащий пару (имя, возраст), где имя - объект класса
    string, а возраст - переменная типа double. Представьте эти члены класса в виде объектов классов
    vector<string> (с именем name) и vector<double> (с именем age). Предусмотрите операцию ввода 
    read_names(), считывающую ряд имен. Предусмотрите операцию read_ages(), предлагающую пользователю
    ввести возраст для каждого имени. Предусмотрите операцию print(), которая выводит на экран пары 
    (name[i],age[i]) (по одной в строке) в порядке, определенном вектором name. Предусмотрите операцию
    sort(), упорядочивающую вектор name в алфавитном порядке и соответствующим образом реорганизующую
    вектор age. Реализуйте все "операции" как функции-члены. Протестируйте этот класс (конечно, тестировать
    надо как можно раньше и чаще).
*/

#include <iostream>
#include <string>
#include <vector>

class NamePairs
{
public:
    void ReadNames();
    void ReadAges();
    void Sort();
    void Print();
private:
    std::vector<std::string> names;
    std::vector<double> ages;
};

void NamePairs::ReadNames()
{
    std::cout << "Введите имена (введите 'СТОП' для остановки): ";
    std::string name;
    while (std::cin)
    {
        std::cin >> name;
        if (name != "СТОП") { names.push_back(name); }
        else { break; }
    }
}

void NamePairs::ReadAges()
{
    std::cout << "Введите возрасты (введите '-1' для остановки): ";
    int age;
    while (std::cin)
    {
        std::cin >> age;
        if (age != -1) { ages.push_back(age); }
        else { break; }
    }
}

void NamePairs::Sort()
{
    std::vector<std::string> namesCopy = names;
    std::vector<double> agesCopy;
    std::sort(names.begin(), names.end());
    for (std::string name : names)
    {
        for (int j = 0; j < namesCopy.size(); ++j)
        {
            if (name == namesCopy[j])
            {
                agesCopy.push_back(ages[j]);
            }
        }
    }
    ages = agesCopy;
}

void NamePairs::Print()
{
    for (int i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << " " << ages[i] << '\n';
    }
}

int main()
{
    NamePairs ns;
    ns.ReadNames();
    ns.ReadAges();
    ns.Print();
    std::cout << "---\n";
    ns.Sort();
    ns.Print();
    return 0;
}
