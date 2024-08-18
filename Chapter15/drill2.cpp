/*
    Вторая часть
 
    Задание, связанное с определением класса.
    1. Определите класс struct Person, содержащий член name типа string и член age типа int.
    2. Определите переменную класса Person, инициализируйте её значением "Goofy" и 63 и выведите на экран (cout).
    3. Определите оператор ввода (>>) и вывода (<<) для класса Person; считайте объект класса Person
    с клавиатуры (cin) и выведите его на экран (cout).
    4. Напишите конструктор класса Person, инициализирующий члены name и age.
    5. Сделайте представление класса Person закрытым и добавьте константные функции-члены name() и age(),
    предназначенные для чтения имени и возраста.
    6. Модифицируйте операторы >> и << для заново определенного класса Person.
    7. Модифицируйте конструктор, чтобы он выполнял проверку, что переменная age лежит в диапазоне [0,150),
    а переменная name не содержит символы ; : " ' [ ] * & ^ % $ # @ !. В случае ошибки используйте функцию
    error(). Протестируйте программу.
    8. Считайте последовательность объектов класса Person с устройства ввода (cin) в вектор типа
    vector<Person>; выведите его на экран (cout). Проверьте правильность ввода.
    9. Измените представление класса Person так, чтобы вместо члена name использовались члены first_name
    и second_name. Отсутствие при вводе обоих этих членов должно считаться ошибкой. Измените операторы
    >> и <<. Протестируйте программу.
    
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool CheckCorrect(std::string name)
{
    std::vector<char> forbiddenSymbols {';', ':', '"', (char)39, '[', ']', '*',
        '&', '^', '%', '$', '#', '@', '!'};
    for (int i = 0; i < name.length(); ++i)
    {
        for (int j = 0; j < forbiddenSymbols.size(); ++j)
        {
            if (name[i] == forbiddenSymbols[j])
            {
                return false;
            }
        }
    }
    return true;
}

struct Person
{
    Person() {}
    Person(std::string f, std::string s, int a) : firstname{f}, surname{s}, age{(unsigned int)a}
    {
        if (!(0 <= a && a < 150 ))
        {
            std::cerr << "Возраст должен быть больше нуля и меньше 150!\n";
            exit(1);
        }
        if (!CheckCorrect(f))
        {
            std::cerr << "Имя содержит недопустимые символы!\n";
            exit(1);
        }
        if (!CheckCorrect(s))
        {
            std::cerr << "Фамилия содержит недопустимые символы!\n";
            exit(1);
        }
    }
    
    std::string GetFirstname() const { return firstname; }
    std::string GetSurame() const { return surname; }
    unsigned int GetAge() const { return age; }
    
private:
    std::string firstname;
    std::string surname;
    unsigned int age;
};

std::istream& operator>>(std::istream& is, Person& p) // Формат ввода: firstname , surname , age
{
    std::string firstname;
    char ch1;
    std::string surname;
    char ch2;
    int age;
    if (!is) { return is; }
    is >> firstname >> ch1 >> surname >> ch2 >> age;
    if (ch1 != ',' || ch2 != ',')
    {
        std::cerr << "Неверный формат ввода!\n";
        exit(1);
    }
    Person some{firstname, surname, age};
    p = some;
    return is;
}

std::ostream& operator<<(std::ostream& os, Person& p)
{
    os << p.GetFirstname() << ' ' << p.GetSurame() << ", " << p.GetAge();
    return os;
}

int main()
{
    std::vector<Person> persons;
    std::cout << "Формат ввода: 'Имя' , 'Фамилия', 'Возраст'. Для остановки введите 'СТОП , 0 , 0'\n";
    for (Person someKind; std::cin >> someKind; )
    {
        if (someKind.GetFirstname() == "СТОП") { break; }
        persons.push_back(someKind);
    }
    for (Person someKind : persons)
    {
        std::cout << someKind << '\n';
    }
    return 0;
}
