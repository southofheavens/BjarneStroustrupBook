/*
    Создайте объект класса vector<double> и скопируйте в него элементы списка типа list<int>, передавая его
    как параметр (по ссылке). Убедитесь, что копия полна и верна. Затем выведите на экран элементы в порядке
    возрастания их значений.
*/

#include <iostream>
#include <vector>
#include <list>

std::vector<double> FromListToVec(const std::list<int>& l)
{
    std::vector<double> out(l.size());
    std::copy(l.cbegin(), l.cend(), out.begin());
    return out;
}

int main()
{
    std::list<int> someList{10,15,20,25,30,35,40,45,50};
    std::vector<double> someVec = FromListToVec(someList);
    
    for (double& el : someVec) {
        std::cout << el << '\n';
    }
    
    return 0;
}
