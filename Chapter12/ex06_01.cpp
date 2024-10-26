/*
 * Что произойдет, если вы нарисуете фигуру, которая не помещается в окне? Что произойдет,
 * если вы нарисуете окно, которое не помещается на экране? Напишите две программы, иллюстрирующие
 * эти эффекты.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex06_01.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Graph.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},600,400,"ex06_01"};

    Rectangle r{{0,0},800,600};
    r.set_fill_color(Color::dark_red);

    win.attach(r);
    win.wait_for_button();
    return 0;
}
