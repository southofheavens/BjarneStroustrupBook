/*
 * Определите класс Striped_rectangle, в котором вместо заполнения прямоугольник заштриховывается горизонтальными
 * линиями толщиной в один пиксель (например, рисуя линии через один пиксель). Поэкспериментируйте с толщиной
 * линий и расстоянием между ними, чтобы добиться желаемого эффекта.
 */

#include "../include/Simple_window.h"
#include "../include/ch14tools.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex05"};
    
    StripedRectangle sr{{100,100},300,200};
    win.attach(sr);
    sr.set_fill_color(Color::black);
    
    win.wait_for_button();
    return 0;
}
