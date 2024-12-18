/*
 * Определите класс Octagon, реализующий правильный восьмиугольник. Напишите тестовую программу, вызывающую
 * все его функции-члены (как определенные вами, так и унаследованные от класса Shape).
 */

#include "../include/Simple_window.h"
#include "../include/ch14tools.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex08"};
    
    Octagon oc{{350,150}, 50};
    oc.set_color(Color::red);
    oc.set_fill_color(Color::dark_red);
    win.attach(oc);
    
    Octagon oc2{{150,150},100};
    win.attach(oc2);
    
    Circle nc{{150,150},100};
    win.attach(nc);

    Circle ic{{150,150}, oc2.GetInside()};
    win.attach(ic);
    
    win.wait_for_button();
    return 0;
}
