/*
 * Нарисуйте окружность. Заставьте метку перемещаться по окружности (пусть она немного сдвигается
 * всякий раз, когда вы щелкаете на кнопке Next).
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex12.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Simple_window.h"

constexpr double PI = 3.14159265;

int main()
{
    Simple_window win{{100,100},600,400,"ex01"};
    
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
        win.wait_for_button();

        ox -= dx;
        oy -= dy;
        i = (i + 15) % 360;
    }
}
