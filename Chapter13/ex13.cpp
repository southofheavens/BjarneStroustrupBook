/*
    Нарисуйте матрицу цветов из раздела 13.10, но без линий, окаймляющих каждый квадрат.
*/

#include "include/Graph.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},600,400,"ex13"};
    
    Vector_ref<Rectangle> vr;
    
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 16; ++j)
        {
            vr.push_back(new Rectangle{Point{i*20,j*20},20,20});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            vr[vr.size()-1].set_color(Color::Transparency::invisible);
            win.attach(vr[vr.size() - 1]);
        }
    }
    
    win.wait_for_button();
    return 0;
}
