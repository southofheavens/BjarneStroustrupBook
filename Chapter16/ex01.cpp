/*
    Создайте класс My_window, аналогичный классу Simple_window, за исключением того, что он имеет две
    кнопки, next и quit.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex01.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/MyWindow.cpp
*/

#include "include/MyWindow.h"

constexpr double PI = 3.14159265;

int main()
{
    MyWindow win{{100,100},600,400,"ex01"};
    
    Circle c{{300,200},100};
    c.set_color(Color::dark_red);
    
    int ox = c.center().x;
    int oy = c.center().y;
    
    Mark m{{ox,oy}, 'x'};
    m.set_color(Color::black);
    
    win.attach(c);
    win.attach(m);
    
    int dx;
    int dy;
    int i = 0;
        
    while(true)
    {
        dx = ox - (c.center().x + cos(i*PI/180)*c.radius());
        dy = oy - (c.center().y + sin(i*PI/180)*c.radius());

        m.move(-dx, -dy);
        win.WaitForPushNext();

        ox -= dx;
        oy -= dy;
        i = (i + 15) % 360;
    }
}
