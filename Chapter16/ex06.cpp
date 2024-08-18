/*
    Создайте "аналоговые часы", т.е. часы с двигающимися стрелками. Определите время, используя средства
    операционной системы. Основная часть этого упражнения - найти функции, определяющие время суток и
    прекращающие выполнение программы на короткий период времени (например, на секунду), а также научиться
    использовать их по имеющейся документации. Указание: clock(), sleep().

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex06.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp \
    src/Arrow.cpp src/Clock.cpp
*/

#include "include/Clock.h"

int main()
{
    Graph_lib::Window* win = new Graph_lib::Window{{100,100},800,600,"ex06"};
    
    Clock* c = new Clock{Point{400,300},150,win};
    win->attach(*c);

    Fl::add_timeout(1.0, Clock::CbRunClock, c);
    
    return gui_main();
}
