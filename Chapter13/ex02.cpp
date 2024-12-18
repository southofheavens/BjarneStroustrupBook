/*
 * Нарисуйте окно с закругленными углами. Определите класс Box, состоящий из четырех линий и четырех дуг.
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex02.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/Box.cpp
 */ 

#include "include/Box.h"
#include "include/Simple_window.h"


int main()
try
{
    using namespace Graph_lib;
    Simple_window win{{100,100},600,400,"ex02"};

    Box b{{100,100},400,200};
    b.set_color(Color::red);
    win.attach(b);

    win.wait_for_button();
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cout << e.what() << '\n';
    return 1;
}
