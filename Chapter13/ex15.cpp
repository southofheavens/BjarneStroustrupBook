/*
    Покройте окно мозаикой из маленьких прямоугольных треугольников.

    P.S. Про цвета ничего не было сказано, поэтому я решил разукрасить треугольники разными цветами.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex15.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/RightTriangle.cpp
*/

#include "include/Graph.h"
#include "include/Simple_window.h"
#include "include/RightTriangle.h"

int main()
try
{
    using namespace Graph_lib;
    Simple_window win{{100,100},601,601,"ex15"};
    
    Vector_ref<RightTriangle> vr;
    
    int startX = 0;
    int startY = 0;
    int width = 20;
    int height = 30;
    
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 60; ++j)
        {
            vr.push_back(new RightTriangle{
                {startX + j % 2 * width, startY + j % 2 * height},
                {startX + width, startY},
                {startX, startY + height}});
            vr[vr.size() - 1].set_fill_color((i*20 + j) % 256);
            win.attach(vr[vr.size() - 1]);
            if (j % 2 == 1)
            {
                startX += width;
            }
        }
        startX = 0;
        startY += height;
    }
        
    win.wait_for_button();
    return 0;
}
catch (const std::invalid_argument& e)
{
    std::cerr << e.what() << '\n';
    return 1;
}
