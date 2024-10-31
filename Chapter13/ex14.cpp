/*
 * Определите класс прямоугольного треугольника. Составьте восьмиугольник из восьми прямоугольных треугольников
 * разного цвета.
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex14.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/RightTriangle.cpp
 */

#include "include/Graph.h"
#include "include/Simple_window.h"
#include "include/RightTriangle.h"

int main()
try
{
    using namespace Graph_lib;
    Simple_window win{{100,100},400,400,"ex14"};
    
    Vector_ref<RightTriangle> vr;
    vr.push_back(new RightTriangle{{150,150}, {50,150}, {150,50}});
    vr.push_back(new RightTriangle{{150,250}, {50,250}, {150,350}});
    vr.push_back(new RightTriangle{{250,250}, {250,350}, {350,250}});
    vr.push_back(new RightTriangle{{250,150}, {250,50}, {350,150}});
    vr.push_back(new RightTriangle{{250,50}, {150,50}, {250,350}});
    vr.push_back(new RightTriangle{{150,350}, {250,350}, {150,50}});
    vr.push_back(new RightTriangle{{50,150}, {50,250}, {350,150}});
    vr.push_back(new RightTriangle{{350,250}, {350,150}, {50,250}});
    
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].set_color(i + 1);
        vr[i].set_fill_color(i + 1);
        win.attach(vr[i]);
    }
        
    win.wait_for_button();
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
