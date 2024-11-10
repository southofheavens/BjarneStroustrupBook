/* 
 * Большинство иерархий классов не связано с графикой. Определите класс Iterator, содержащий чисто
 * виртуальную функцию next(), возвращающую указатель типа double* (см. главу 17). Теперь унаследуйте
 * от класса Iterator классы Vector_iterator и List_iterator так, чтобы функция next() для класса
 * Vector_iterator возвращала указатель на следующий элемент вектора типа vector<double>, а для класса
 * List_iterator делала то же самое для списка типа list<double>. Инициализируйте объект класса
 * Vector_iterator вектором vector<double>, и первый вызов функции next() должен возвращать указатель
 * на первый элемент вектора, если таковой существует. Если такого элемента нет, верните нуль. Проверьте
 * этот класс с помощью функции void print(Iterator&), выводящей на печать элементы вектора типа 
 * vector<double> и списка типа list<double>.
 * 
 * P.S. Я вернулся к этому заданию после того, как прочитал все последующие главы вплоть до 21-й.
 * Такие понятия, как std::vector<double>::iterator и std::list<double>::iterator будут описаны в одной
 * из следующих глав. К сожалению, я не могу догадаться, как выполнить это упражнение без применения 
 * итераторов (если это вообще возможно), поэтому пришлось прибегнуть к их использованию.
 */

#include <iostream>
#include <vector>
#include <list> 

class Iterator
{
public:
    virtual double* Next() = 0;
};

class VectorIterator : public Iterator
{
private:
    std::vector<double> vec;
    std::vector<double>::iterator it;

public:
    VectorIterator(std::vector<double> v) : vec{v}, it{vec.begin()} {}
    double* Next() override;
};

double* VectorIterator::Next()
{
    if (it != vec.end())
    {
        std::vector<double>::iterator next = it;
        it++;
        return &*next;
    }
    return nullptr;
}

class ListIterator : public Iterator 
{
private:
    std::list<double> lst;
    std::list<double>::iterator it;

public:
    ListIterator(std::list<double> l) : lst{l}, it{lst.begin()} {}
    double* Next() override;
};

double* ListIterator::Next()
{
    if (it != lst.end())
    {
        std::list<double>::iterator next = it;
        it++;
        return &*next;
    }
    return nullptr;
}

void Print(Iterator& it)
{
    double* ptr = it.Next();
    while (ptr != nullptr)
    {
        std::cout << *ptr << ' ';
        ptr = it.Next();
    }
    std::cout << '\n';
}

int main()
{
    VectorIterator vi({1,2,3,4,5});
    ListIterator li({6,7,8,9,10});

    Print(vi);
    Print(li);

    return 0;
}
