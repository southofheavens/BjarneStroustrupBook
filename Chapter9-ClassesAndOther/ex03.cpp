/*
    Замените функцию Name_pair::print() (глобальным) оператором operator<< b и определите операции
    == и != для объектов класса Name_pair.
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
    
    int64_t GetSize() const { return names.size(); }
    std::string GetName(int index) const { return names[index];}
    int GetAge(int index) const { return ages[index];}

private:
    std::vector<std::string> names;
    std::vector<double> ages;

    friend bool operator==(const NamePairs& first, const NamePairs& second);
    friend bool operator!=(const NamePairs& first, const NamePairs& second);
};

std::ostream& operator<<(std::ostream& os, NamePairs np)
{
    for (int i = 0; i < np.GetSize(); ++i)
    {
        os << np.GetName(i) << " is " << np.GetAge(i) << " years old.\n";
    }
    return os;
}

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

bool operator==(const NamePairs& first, const NamePairs& second) 
{
    if (first.GetSize() != second.GetSize())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < first.GetSize(); ++i)
        {
            if (first.names[i] != second.names[i])
            {
                return 0;
            }
        }
        for (int i = 0; i < first.GetSize(); ++i)
        {
            if (first.ages[i] != second.ages[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

bool operator!=(const NamePairs& first, const NamePairs& second) 
{
    return !(first == second);
}

int main()
{
    NamePairs ns1;
    ns1.ReadNames();
    ns1.ReadAges();
    std::cout << ns1;
    std::cout << "---\n";

    NamePairs ns2;
    ns2.ReadNames();
    ns2.ReadAges();
    std::cout << ns2;
    
    ns1.Sort();
    ns2.Sort();
    std::cout << (ns1 == ns2) << " " << (ns1 != ns2) << '\n';
    
    return 0;
}
