/*
    Определите класс Immobile_Circle, который во всем похож на класс Circle, но объекты которого не способны
    перемещаться.

    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex04.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
*/

#include "include/Simple_window.h"
#include "include/ImmobileCircle.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex04"};
    
    Circle c{{150,150},50};
    win.attach(c);
    c.move(50,50);
    
    ImmobileCircle i{{350,150},50};
    win.attach(i);
    i.move(50,50);
    
    win.wait_for_button();
    return 0;
}
