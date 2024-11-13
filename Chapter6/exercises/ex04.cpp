/*
 * Определите класс Name_value, хранящий строку и значение. Повторите упр. 19 из главы 4, используя
 * вместо двух векторов вектор vector<Name_value>
 */

#include <iostream>
#include <vector>
#include <string>

struct NameValue
{
    std::string name;
    int score;
};

int main()
{
    std::cout << "Введите пары вида 'Имя значение'. Для остановки ввода введите 'NoName 0'.\n";
    std::vector<NameValue> persons;
    NameValue person;
    for (NameValue person; std::cin >> person.name >> person.score;)
    {
        if (person.name != "NoName" && person.score != 0)
        {
            persons.push_back(person);
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < persons.size() - 1; ++i)
    {
        if (persons[i].name == persons[i + 1].name)
        {
            std::cout << "Каждое имя должно встречаться не более одного раза!\n";
            exit (1);
        }
    }
    std::cout << "---\n";
    for (NameValue person : persons)
    {
        std::cout << person.name << " " << person.score << '\n';
    }
    return 0;
}
