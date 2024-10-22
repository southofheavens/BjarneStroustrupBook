/*
    Теперь поработайте с контейнером map
    
    1. Определите контейнер map<string,int> с именем msi.
    2. Вставьте в него десять пар (имя, значение), например msi["lecture"]=21.
    3. Выведите пары (имя, значение) в поток cout в удобном для вас виде.
    4. Удалите пары (имя, значение) из контейнера msi.
    5. Напишите функцию, считывающую пары (имя, значение) из потока cin и помещающую их в контейнер msi.
    6. Прочитайте десять пар (имя, значение) из потока ввода и поместите их в контейнер msi.
    7. Выведите элементы контейнера msi в поток cout.
    8. Выведите сумму (целочисленных) значений из контейнера msi.
    9. Определите контейнер map<int,string> с именем mis.
    10. Введите значения из контейнера msi в контейнер mis; иначе говоря, если в контейнере msi
    есть элемент ("lecture",21), то контейнер mis должен содержать элемент (21,"lecture").
    11. Выведите элементы контейнера mis в поток cout.
*/

#include <map>
#include <string>
#include <iostream>
#include <numeric>  //  Эта директива предоставляет доступ к функции accumulate.

template<typename K, typename V>
void ScanfPair(std::map<K,V>& m)
{
    K key;
    V value;
    std::cin >> key >> value;
    m[key] = value;
}

int main()
{
    std::cout << "msi:\n";
    std::map<std::string,int> msi;
    msi["auto"] = 5;
    msi["clock"] = 15;
    msi["watermelon"] = -7;
    msi["wall"] = 1000;
    msi["book"] = 501;
    msi["home"] = 10005;
    msi["earth"] = 0;
    msi["mouse"] = 936;
    msi["forest"] = -2005;
    msi["metal"] = 111111;
    
    // ---------------
    
    for (std::pair<std::string,int> p : msi) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
    
    // ---------------
    
    msi.erase(msi.begin(), msi.end());
    std::cout << '\n';
    
    // ---------------
    
    std::cout << "Ввод данных:\n";
    for (int i = 0, countOfElems=10; i < countOfElems; ++i) {
        ScanfPair(msi);
    }
    std::cout << '\n';
    for (std::pair<std::string,int> p : msi) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
    
    // ---------------
    
    int sum = accumulate(msi.begin(),msi.end(),0,[](int acc, const auto& pair) {
        return acc + pair.second;
      });
    std::cout << "Сумма целочисленных элементов = " << sum << '\n';
    
    // ---------------
    
    std::cout << "\nmis:\n";
    std::map<int,std::string> mis;
    for (std::pair<std::string,int> p : msi) {
        mis[p.second] = p.first;
    }
    for (std::pair<int,std::string> p : mis) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
        
    return 0;
}
