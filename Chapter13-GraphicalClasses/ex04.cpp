/*
    Определите функции n(), s(), e(), w(), center(), ne(), se(), sw(), и nw(). Каждая из них должна
    получать аргумент типа Rectangle и возвращать объект типа Point. Эти функции должны определять 
    "точки подключения", расположенные на границах и внутри прямоугольника. Например, nw(r) - это 
    левый верхний (северо-западный) угол объекта класса Rectangle с именем r.
*/  

#include "include/Graph.h"

Point N(const Graph_lib::Rectangle& r) // Север
{
    Point p(r.point(0).x + r.width() / 2, r.point(0).y);
    return p;
}

Point S(const Graph_lib::Rectangle& r) // Юг
{
    Point p(r.point(0).x + r.width() / 2, r.point(0).y + r.height());
    return p;
}

Point E(const Graph_lib::Rectangle& r) // Восток
{
    Point p(r.point(0).x + r.width(), r.point(0).y + r.height() / 2);
    return p;
}

Point W(const Graph_lib::Rectangle& r) // Запад
{
    Point p(r.point(0).x, r.point(0).y + r.height() / 2);
    return p;
}

Point Center(const Graph_lib::Rectangle& r) // Центр
{
    Point p(r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2);
    return p;
}

Point Ne(const Graph_lib::Rectangle& r) // Северо-восток
{
    Point p(r.point(0).x + r.width(), r.point(0).y);
    return p;
}

Point Se(const Graph_lib::Rectangle& r) // Юго-восток
{
    Point p(r.point(0).x + r.width(), r.point(0).y + r.height());
    return p;
}

Point Sw(const Graph_lib::Rectangle& r) // Юго-запад
{
    Point p(r.point(0).x, r.point(0).y + r.height());
    return p;
}   

Point Nw(const Graph_lib::Rectangle& r) // Северо-запад
{
    Point p(r.point(0).x, r.point(0).y);
    return p;
}

int main()
{
    using namespace Graph_lib;

    Rectangle r({100,100}, 300, 200);

    std::cout << N(r).x << ' ' << N(r).y << '\n';
    std::cout << S(r).x << ' ' << S(r).y << '\n';
    std::cout << E(r).x << ' ' << E(r).y << '\n';
    std::cout << W(r).x << ' ' << W(r).y << '\n';
    std::cout << Center(r).x << ' ' << Center(r).y << '\n';
    std::cout << Ne(r).x << ' ' << Ne(r).y << '\n';
    std::cout << Se(r).x << ' ' << Se(r).y << '\n';
    std::cout << Sw(r).x << ' ' << Sw(r).y << '\n';
    std::cout << Nw(r).x << ' ' << Nw(r).y << '\n';

    return 0;
}
