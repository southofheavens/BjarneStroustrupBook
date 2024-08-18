/*
    Постройте графики функций sin(), cos(), sin(x) + cos(x) и sin(x)*sin(x)+cos(x)*cos(x) на одном рисунке.
    Изобразите оси и метки.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex04.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
*/

#include "include/Window.h"
#include "include/Graph.h"

constexpr unsigned int X_MAX = 750; // Размер окна
constexpr unsigned int Y_MAX = 750;

constexpr unsigned int DIVISION_SCALE = 20; // Размер одного деления

constexpr unsigned int X_ORIG = X_MAX / 2; // Центр окна
constexpr unsigned int Y_ORIG = Y_MAX / 2;
const Point ORIG{X_ORIG, Y_ORIG};

constexpr unsigned int X_LENGTH = 600; // Длины осей
constexpr unsigned int Y_LENGTH = 600;

constexpr int R_MIN = -15; // Диапазон
constexpr int R_MAX = 15;

constexpr unsigned int N_POINTS = 600; // Количество точек в диапазоне

int main()
{
    Graph_lib::Window win{X_MAX,Y_MAX,"ex04"};
    using namespace Graph_lib;
        
    Axis x{Axis::x, Point{(X_MAX - X_LENGTH) / 2, Y_ORIG},
            X_LENGTH, X_LENGTH / DIVISION_SCALE, "1 == 20 пикселей"};
    Axis y{Axis::y, Point{X_ORIG, Y_LENGTH + (Y_MAX - Y_LENGTH) / 2},
            Y_LENGTH, Y_LENGTH / DIVISION_SCALE, "1 == 20 пикселей"};
    win.attach(x);
    win.attach(y);
    
    Function f1{[](double x){return sin(x);}, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Function f2{[](double x){return cos(x);}, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Function f3{[](double x){return sin(x) + cos(x);},
        R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Function f4{[](double x){return sin(x)*sin(x)+cos(x)*cos(x);},
        R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    
    Text sinMark{{75,410}, "sin(x)"};
    Text cosMark{{175,410}, "cos(x)"};
    Text sinCosMark{{110,340}, "sin(x)+cos(x)"};
    Text SinCosMark2{{260,340}, "sin(x)*sin(x)+cos(x)*cos(x)"};
    
    f1.set_color(Color::red);
    win.attach(f1);
    sinMark.set_color(Color::red);
    win.attach(sinMark);
    f2.set_color(Color::yellow);
    win.attach(f2);
    cosMark.set_color(Color::yellow);
    win.attach(cosMark);
    f3.set_color(Color::green);
    win.attach(f3);
    sinCosMark.set_color(Color::green);
    win.attach(sinCosMark);
    f4.set_color(Color::cyan);
    win.attach(f4);
    SinCosMark2.set_color(Color::cyan);
    win.attach(SinCosMark2);
    
    gui_main();
    return 0;
}
