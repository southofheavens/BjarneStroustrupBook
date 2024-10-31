/*
 * Определите класс Arrow, рисующий стрелки.
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex03.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/Arrow.cpp
 */

#include "include/Arrow.h"
#include "include/Simple_window.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex03"};
    
    Arrow a{{100,100},{200,200}};
    win.attach(a);
    
    win.wait_for_button();
    return 0;
}
