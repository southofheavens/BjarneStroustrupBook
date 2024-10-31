/*
 * Нарисуйте эллипс размером 300x200 пикселей. Нарисуйте ось x длиной 400 пикселей и ось y длиной 300 пикселей,
 * проходящие через центр эллипса. Пометьте фокусы. Отметьте на эллипсе точку, которая не принадлежит ни одной
 * из осей. Соедините эту точку с фокусами двумя линиями.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex11.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp 
 */

#include "include/Graph.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},450,350,"ex11"};
    
    Ellipse el{{225,175},150,100};
    Axis xa{Axis::x, Point{25, 175}, 400, 20};
    Axis ya{Axis::y, Point{225,325}, 300, 20};
    Mark l{{75,175},'x'};
    l.set_color(Color::red);
    Mark r{{375,175},'x'};
    r.set_color(Color::red);
    Mark p{{300,88},'x'};
    p.set_color(Color::red);
    Line fromPtoL{{300,88},{75,175}};
    Line fromPtoR{{300,88},{375,175}};
    
    win.attach(el);
    win.attach(xa);
    win.attach(ya);
    win.attach(l);
    win.attach(r);
    win.attach(p);
    win.attach(fromPtoL);
    win.attach(fromPtoR);
    
    win.wait_for_button();
    return 0;
}
