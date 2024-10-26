/*
 * Нарисуйте объект класса Rectangle с размерами 100x30 и поместите в него текст "Howdy!"
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex02.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 400, "ex02");

    Rectangle r({100,100}, 100, 30);
    win.attach(r);

    Text t(Point{125, 120}, "Howdy!");
    win.attach(t);

    win.wait_for_button();
    return 0;
}
