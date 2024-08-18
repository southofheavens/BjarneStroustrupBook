/*
    Определите класс Fct, который почти совпадает с классом Function, за исключением того, что он хранит
    аргументы, переданные конструктору. Включите в класс Fct операции "восстановления" параметров, чтобы
    мы могли повторять вычисления с разными диапазонами, функциями и т.д.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex02.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/Fctn.cpp
*/

#include "include/Simple_window.h"
#include "include/Fctn.h"

double slope(double x) { return x/2; }
double square(double x) { return x*x; }

int main()
{
    Simple_window win{{100,100},600,400,"ex02"};
    using namespace Graph_lib;
    
    Fctn s{square, -10, 11, {300,200}, 400};
    win.attach(s);
    
    win.wait_for_button();
    s.SetFunction(slope);
    
    win.wait_for_button();
    s.SetRange(-5,6);
    
    win.wait_for_button();
    s.SetOrig({250,175});
    
    win.wait_for_button();
    s.SetCount(300);
    
    win.wait_for_button();
    s.SetScale(20, 20);
    
    win.wait_for_button();
    return 0;
}
