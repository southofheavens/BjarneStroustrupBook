/*
 * Определите функции из упр. 4 для классов Circle и Ellipse. Разместите точки подключения внутри или вне фигур,
 * но не за пределами описанного вокруг них прямоугольника.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex05.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp 
 */

#include "include/Graph.h"

// Функции для Circle

Point N(const Graph_lib::Circle& c) // Север
{
    Point p(c.point(0).x + c.radius(), c.point(0).y);
    return p;
}

Point S(const Graph_lib::Circle& c) // Юг
{
    Point p(c.point(0).x + c.radius(), c.point(0).y + 2 * c.radius());
    return p;
}

Point E(const Graph_lib::Circle& c) // Восток
{
    Point p(c.point(0).x + 2 * c.radius(), c.point(0).y + c.radius());
    return p;
}

Point W(const Graph_lib::Circle& c) // Запад
{
    Point p(c.point(0).x, c.point(0).y + c.radius());
    return p;
}

Point Center(const Graph_lib::Circle& c) // Центр
{
    Point p(c.point(0).x + c.radius(), c.point(0).y + c.radius());
    return p;
}

Point Ne(const Graph_lib::Circle& c) // Северо-восток
{
    Point p(c.point(0).x + 2 * c.radius(), c.point(0).y);
    return p;
}

Point Se(const Graph_lib::Circle& c) // Юго-восток
{
    Point p(c.point(0).x + 2 * c.radius(), c.point(0).y + 2 * c.radius());
    return p;
}

Point Sw(const Graph_lib::Circle& c) // Юго-запад
{
    Point p(c.point(0).x, c.point(0).y + 2 * c.radius());
    return p;
}

Point Nw(const Graph_lib::Circle& c) // Северо-запад
{
    Point p(c.point(0).x, c.point(0).y);
    return p;
}

// Функции для Ellipse

Point N(const Graph_lib::Ellipse& c) // Север
{
    Point p(c.point(0).x + c.major(), c.point(0).y);
    return p;
}

Point S(const Graph_lib::Ellipse& c) // Юг
{
    Point p(c.point(0).x + c.major(), c.point(0).y + 2 * c.minor());
    return p;
}

Point E(const Graph_lib::Ellipse& c) // Восток
{
    Point p(c.point(0).x + 2 * c.major(), c.point(0).y + c.minor());
    return p;
}

Point W(const Graph_lib::Ellipse& c) // Запад
{
    Point p(c.point(0).x, c.point(0).y + c.minor());
    return p;
}

Point Center(const Graph_lib::Ellipse& c) // Центр
{
    Point p(c.point(0).x + c.major(), c.point(0).y + c.minor());
    return p;
}

Point Ne(const Graph_lib::Ellipse& c) // Северо-восток
{
    Point p(c.point(0).x + 2 * c.major(), c.point(0).y);
    return p;
}

Point Se(const Graph_lib::Ellipse& c) // Юго-восток
{
    Point p(c.point(0).x + 2 * c.major(), c.point(0).y + 2 * c.minor());
    return p;
}

Point Sw(const Graph_lib::Ellipse& c) // Юго-запад
{
    Point p(c.point(0).x, c.point(0).y + 2 * c.minor());
    return p;
}

Point Nw(const Graph_lib::Ellipse& c) // Северо-запад
{
    Point p(c.point(0).x, c.point(0).y);
    return p;
}

int main()
{
    using namespace Graph_lib;
    
    Circle c{{300,200}, 100};
    std::cout << "Circle\n";
    std::cout << N(c).x << ' ' << N(c).y << '\n';
    std::cout << S(c).x << ' ' << S(c).y << '\n';
    std::cout << E(c).x << ' ' << E(c).y << '\n';
    std::cout << W(c).x << ' ' << W(c).y << '\n';
    std::cout << Center(c).x << ' ' << Center(c).y << '\n';
    std::cout << Ne(c).x << ' ' << Ne(c).y << '\n';
    std::cout << Se(c).x << ' ' << Se(c).y << '\n';
    std::cout << Sw(c).x << ' ' << Sw(c).y << '\n';
    std::cout << Nw(c).x << ' ' << Nw(c).y << '\n' << ">\n";
    
    Ellipse e{{300,200},200,100};
    std::cout << "Ellipse\n";
    std::cout << N(e).x << ' ' << N(e).y << '\n';
    std::cout << S(e).x << ' ' << S(e).y << '\n';
    std::cout << E(e).x << ' ' << E(e).y << '\n';
    std::cout << W(e).x << ' ' << W(e).y << '\n';
    std::cout << Center(e).x << ' ' << Center(e).y << '\n';
    std::cout << Ne(e).x << ' ' << Ne(e).y << '\n';
    std::cout << Se(e).x << ' ' << Se(e).y << '\n';
    std::cout << Sw(e).x << ' ' << Sw(e).y << '\n';
    std::cout << Nw(e).x << ' ' << Nw(e).y << '\n';
    
    return 0;
}
