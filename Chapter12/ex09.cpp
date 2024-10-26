/*
 * Выведите на экран фотографию вашего друга. Напишите его имя в заголовке окна и в заголовке внутри окна.

 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex09.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 500, "Hans");

    Image ii{Point{100, 50}, "resources/Hans.jpg"};
    win.attach(ii); 

    Text t(Point{225, 30}, "My friend Hans");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    win.wait_for_button();
    return 0;
}
