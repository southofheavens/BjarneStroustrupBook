/*
    Создайте меню с пунктами "окружность", "квадрат", "равносторонний треугольник" и "шестиугольник". Создайте
    окно ввода (или два таких окна) для ввода пар координат и разместите фигуру, созданную после щелчка на
    соответствующей кнопке, в заданной точке.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex04.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/MyWindow.cpp \
    src/ShapeWindow.cpp src/RegularTriangle.cpp src/RegularHexagon.cpp
*/

#include "include/ShapeWindow.h"

int main()
{
    ShapeWindow win{{100,100},800,600,"ex04"};
    
    return gui_main();
}
