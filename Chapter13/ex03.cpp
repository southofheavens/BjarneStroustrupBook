/*
    Определите класс Arrow, рисующий стрелки.
*/

#include "include/Arrow.h"
#include "include/Simple_window.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex03"};
    
    Arrow a{{100,100},{200,200}};
    win.attach(a);
    
    win.wait_for_button();
    return 0;
}
