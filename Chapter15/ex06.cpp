/*
    Разработайте и реализуйте класс для построения гистограммы. Его исходные данные должны храниться в
    векторе типа vector<double>, в котором записаны N значений и каждое значение представляется
    "столбиком", т.е. прямоугольником с соответствующей высотой.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex06.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/Histogram.cpp
*/

#include "include/Window.h"
#include "include/Histogram.h"

constexpr unsigned int X_MAX = 600; // Размер окна
constexpr unsigned int Y_MAX = 600;

int main()
{
    Graph_lib::Window win{{100,100}, X_MAX, Y_MAX, "ex06"};
    
    Histogram hg{{100,100},400,400};
    hg.SetValues(5);
    win.attach(hg);
    
    gui_main();
    return 0;
}
