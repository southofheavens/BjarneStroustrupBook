/*
 * Программисты, работающие на языке C++, разговаривая с программистами, работающими на языке C, рефреном
 * повторяют: "Все, что делаешь ты, я могу сделать лучше!" Перепишите пример с контейнером List на языке C++,
 * продемонстрировав, что это можно сделать короче и проще без замедления программы или увеличения объектов.
 *
 * How to compile:
 * clang++ -std=c++14 tryThis3.cpp src/ListCpp.cpp
 */

#include <iostream>
#include "include/ListCpp.h"

Link* Advance(Link* p, int n)
{
    while (n != 0)
    {
        if (n < 0)
        {
            p=p->prev;
            n++;
        }
        else
        {
            p=p->succ;
            n--;
        }
    }
    return p;
}

int main()
{
    List lst;
    lst.PushBack((struct Link*)MakeName("Semyon"));
    lst.PushBack((struct Link*)MakeName("Anton"));
    lst.PushBack((struct Link*)MakeName("David"));
    lst.PushBack((struct Link*)MakeName("Varya"));
    lst.PushBack((struct Link*)MakeName("Dima"));
    
    lst.Erase(lst.Head());
    lst.Erase(Advance(lst.Head(),3));
    lst.Erase(Advance(lst.Head(),1));
    
    Link* head = lst.Head();
    while (head)
    {
        std::cout << ((struct Name*)head)->n << '\n';
        head = head->succ;
    }
    
    return 0;
}
