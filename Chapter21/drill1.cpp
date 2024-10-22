/*
    Задание
    После выполнения каждой операции выводите содержимое вектора на экран.
    1. Определите структуру struct Item { string name; int iid; double value; // ...  };, создайте контейнер
    vector<Item> с именем vi и заполните его десятью элементами, считанными из файла.
    2. Отсортируйте контейнер vi по полю name.
    3. Отсортируйте контейнер vi по полю iid.
    4. Отсортируйте контейнер vi по полю value; выведите его содержимое на экран в порядке убывания значений
    (т.е. самое большое значение должно быть выведено первым).
    5. Вставьте в контейнер элементы Item("horse shoe",99,12.34) и Item("Canon S400",9988,499.95).
    6. Удалите два элемента Item из контейнера vi, задавая значение поля name удаляемого элемента.
    7. Удалите два элемента Item из контейнера vi, задавая значение поля iid удаляемого элемента.
    8. Повторите упражнение с контейнером типа list<Item> вместо vector<Item>
 
    data.txt:
    banana 100 5.5
    april 250 1.5
    carrot 75 7.75
    donut 500 1
    cold 5 5
    winter 15 7.77
    mother 99 99.99
    chair 10000 10
    sun 1 2
    frog 5 5.12
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

struct Item
{
    std::string name;
    int iid;
    double value;
    Item(std::string n, int i, double v) : name{n}, iid{i}, value{v} {}
    // ...
};

int main()
{
    // vector<Item> ---------------------------
    
    std::cout << "Working with std::vector<Item>:\n";
    std::vector<Item> vi;
    std::ifstream ifs{"data.txt"};
    if (ifs.fail()) 
    { 
        std::cout << "Ошибка чтения файла!\n";
        return 1; 
    }
    
    std::string name;
    int iid;
    double value;
    while (ifs >> name >> iid >> value)
    {
        vi.push_back(Item(name,iid,value));
    }
    
    // ---------------
    
    sort(vi.begin(), vi.end(), [](Item first, Item second){ return first.name < second.name; });
    std::cout << "Отсортировали контейнер vi по полю name:\n";
    for (Item i : vi) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }
    
    // ---------------
    
    sort(vi.begin(), vi.end(), [](Item first, Item second){ return first.iid < second.iid; });
    std::cout << "Отсортировали контейнер vi по полю iid:\n";
    for (Item i : vi) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }
    
    // ---------------
    
    sort(vi.begin(), vi.end(), [](Item first, Item second){ return first.value > second.value; });
    std::cout << "Отсортировали контейнер vi по полю value в порядке убывания:\n";
    for (Item i : vi) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }
    
    // ---------------
    
    vi.push_back(Item("horse shoe",99,12.34));
    vi.push_back(Item("Canon S400",9988,499.95));
    
    // ---------------
    
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& item){ return item.name == "cold"; }));
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& item){ return item.name == "april"; }));
    
    // ---------------
    
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& item){ return item.iid == 75; }));
    vi.erase(std::find_if(vi.begin(), vi.end(), [](const Item& item){ return item.iid == 100; }));
    
    std::cout << "Удалили из контейнера vi элементы с полями name == 'cold' и name == 'april',\n";
    std::cout << "iid == 75 и iid = 100:\n";
    for (Item i : vi) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << ' ' << '\n';
    }
    std::cout << '\n';
    
    // list<Item> ---------------------------
    
    std::cout << "Working with std::list<Item>:\n";
    std::list<Item> li;
    ifs.clear();
    ifs.seekg(0);
    
    while (ifs >> name >> iid >> value)
    {
        li.push_back(Item(name,iid,value));
    }
    
    // ---------------
    
    // li.sort():  Метод  sort  для  std::list  использует алгоритм
    // сортировки слиянием,  который подходит для сортировки связанных списков.
    
    li.sort([](const Item& first, const Item& second){ return first.name < second.name; });
    std::cout << "Отсортировали контейнер li по полю name:\n";
    for (Item i : li) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }

    // ---------------
    
    li.sort([](const Item& first, const Item& second){ return first.iid < second.iid; });
    std::cout << "Отсортировали контейнер li по полю iid:\n";
    for (Item i : li) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }

    // ---------------
    
    li.sort([](const Item& first, const Item& second){ return first.value > second.value; });
    std::cout << "Отсортировали контейнер li по полю value в порядке убывания:\n";
    for (Item i : li) {
        std::cout << i.name << ' ' << i.iid << ' ' << i.value << '\n';
    }
    
    // ---------------
    
    li.push_back(Item("horse shoe",99,12.34));
    li.push_back(Item("Canon S400",9988,499.95));
    
    // ---------------
    
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& item){ return item.name == "chair"; }));
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& item){ return item.name == "winter"; }));
    
    // ---------------
    
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& item){ return item.iid == 5; }));
    li.erase(std::find_if(li.begin(), li.end(), [](const Item& item){ return item.iid == 500; }));
    
    std::cout << "Удалили из контейнера li элементы с полями name == 'chair' и name == 'winter',\n";
    std::cout << "iid == 5 и iid = 500:\n";
    for (Item i : li) {
        std::cout << i.name << '\n';
    }
    
    ifs.close();
    return 0;
}
