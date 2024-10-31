/*
 * Определите класс Arc, рисующий часть эллипса. Указание: fl_arc();
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex01.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/Arc.cpp
 */

#include "include/Arc.h"
#include "include/Simple_window.h"

using namespace Graph_lib;

int main()
{
    Simple_window win({100,100}, 600, 400, "ex01");

    Arc a1(Point{300, 200}, 100, 100, 0, 360);
    a1.set_color(Color::blue);
    win.attach(a1);

    Arc a2(Point{300, 200}, 100, 100, 90, 180);
    a2.set_color(Color::red);
    win.attach(a2);

    Arc a3(Point{300, 200}, 150, 150, 90, 360);
    a3.set_color(Color::green);
    win.attach(a3);

    Arc a4(Point{300, 200}, 100, 100, 270, 360);
    a4.set_color(Color::red);
    win.attach(a4);

    Arc a5(Point{300,200}, 50, 50, 0, 360);
    a5.set_color(Color::yellow);
    win.attach(a5);

    Arc a6(Point{300,200}, 100, 50, 0, 360);
    a6.set_color(Color::cyan);
    win.attach(a6);

    win.wait_for_button();
    return 0;
}
