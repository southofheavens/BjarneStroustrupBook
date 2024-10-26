/*
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex06_02.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Simple_window.h"
#include "include/Graph.h"

const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 900;

int main()
{
    using namespace Graph_lib;
    Simple_window win{{0,0},SCREEN_WIDTH+1000,SCREEN_HEIGHT+1000,"ex06_02"};

    win.wait_for_button();
    return 0;
}