/*
    Определите класс Striped_rectangle, в котором вместо заполнения прямоугольник заштриховывается горизонтальными
    линиями толщиной в один пиксель (например, рисуя линии через один пиксель). Поэкспериментируйте с толщиной
    линий и расстоянием между ними, чтобы добиться желаемого эффекта.

    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex05.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/StripedRectangle.cpp
*/

#include "include/Simple_window.h"
#include "include/StripedRectangle.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex05"};
    
    StripedRectangle sr{{100,100},300,200};
    win.attach(sr);
    sr.set_fill_color(Color::black);
    
    win.wait_for_button();
    return 0;
}
