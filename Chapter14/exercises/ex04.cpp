/*
 * Определите класс Immobile_Circle, который во всем похож на класс Circle, но объекты которого не способны
 * перемещаться.
 */

#include "../include/Simple_window.h"
#include "../include/ch14tools.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex04"};
    
    Circle c{{150,150},50};
    win.attach(c);
    c.move(50,50);
    
    ImmobileCircle i{{350,150},50};
    win.attach(i);
    i.move(50,50);
    
    win.wait_for_button();
    return 0;
}
