/*
    Покройте часть окна мозаикой из объектов класса Regular_hexagon (используйте не меньше восьми шестиугольников).

    P.S. Про цвета ничего не было сказано, поэтому я решил разукрасить шестиугольники разными цветами.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex09.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/RegularHexagon.cpp
*/

#include "include/RegularHexagon.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},750,250,"ex09"};
    
    Vector_ref<RegularHexagon> vr;
    int hexBigR = 15;
    int hexSmallR = hexBigR * sqrt(3) / 2;
    
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16; ++j)
        {
            vr.push_back(new RegularHexagon{
                {hexBigR + j * (2 * hexBigR + hexSmallR) + i % 2 * (hexBigR + hexSmallR / 2),
                    hexSmallR + i * hexSmallR},
                hexBigR});
            vr[vr.size() - 1].set_fill_color(Color{i*16+j});
            win.attach(vr[vr.size() - 1]);
        }
    }
    
    win.wait_for_button();
    return 0;
}
