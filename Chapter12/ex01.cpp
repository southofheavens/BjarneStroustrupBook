/*
 * Нарисуйте прямоугольник как объект класса Rectangle и как объект класса Polygon. Сделайте линии объекта 
 * класса Polygon красными, а линии объекта класса Rectangle - синими.
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex01.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100, 100}, 600, 400, "ex01");

    Rectangle r{{100, 100}, 100, 50};
    r.set_color(Color::red);
    win.attach(r);

    Polygon p;
    p.add(Point{250, 100});
    p.add(Point{250, 150});
    p.add(Point{350, 150});
    p.add(Point{350, 100});
    p.set_color(Color::blue);
    win.attach(p);

    win.wait_for_button();
    return 0;
}
