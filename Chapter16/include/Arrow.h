// for ex06

#include "Graph.h"

using namespace Graph_lib;

struct Arrow : Shape
{
    Arrow(Point tail, Point tip)
    {
        add(tail);
        add(tip);
    }
    
    void draw_lines() const;
    
    void SetTail(Point p);
    void SetTip(Point p);
    
private:
    int size = 12; // Общий размер наконечника
    int iso = 14; // Толщина или угол наконечника
};
