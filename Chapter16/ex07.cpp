/*
    Используя приемы из предыдущих упражнений, создайте изображение самолёта, летящего по экрану. Добавьте
    кнопки Start и Stop.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex07.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/AirplaneWindow.cpp
*/

#include "include/AirplaneWindow.h"

int main()
{
    AirplaneWindow* win = new AirplaneWindow{{100,100},800,600,"ex07"};
    
    return gui_main();
}
