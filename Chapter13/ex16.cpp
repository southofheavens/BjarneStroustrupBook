/*
 * Выполните предыдущее упражнение с шестиугольниками.
 *
 * P.S. Про цвета ничего не было сказано, поэтому я решил разукрасить треугольники разными цветами.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex16.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/RegularHexagon.cpp
 */

#include "include/RegularHexagon.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},598,601,"ex16"};
    
    Vector_ref<RegularHexagon> vr;
    int hexBigR = 15;
    int hexSmallR = hexBigR * sqrt(3) / 2;
    
    for (int i = 0; i < 49; ++i)
    {
        for (int j = 0; j < 14; ++j)
        {
            vr.push_back(new RegularHexagon{
                {hexBigR + j * (2 * hexBigR + hexSmallR) + i % 2 * (hexBigR + hexSmallR / 2),
                    hexSmallR + i * hexSmallR},
                hexBigR});
            vr[vr.size() - 1].set_fill_color(Color{(i*49+j) % 256});
            win.attach(vr[vr.size() - 1]);
        }
    }
    
    win.wait_for_button();
    return 0;
}
