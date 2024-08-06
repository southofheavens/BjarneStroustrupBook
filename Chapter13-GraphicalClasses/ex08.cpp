/*
    Определите класс Regular_hexagon (правильный шестиугольник). В качестве аргументов конструктора используйте
    центр и расстояние от центра до угловой точки.

    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex08.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/RegularHexagon.cpp
*/

#include "include/RegularHexagon.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},600,400,"ex08"};
    
    RegularHexagon h{{200,200},100};
    h.set_fill_color(Color::yellow);
    win.attach(h);
    
    win.wait_for_button();
    return 0;
}
