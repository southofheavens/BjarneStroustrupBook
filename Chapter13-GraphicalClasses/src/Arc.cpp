#include "../include/Arc.h"

Arc::Arc(Point p, int w, int h, int s, int e) : width{w}, height{h}, start{s}, end{e}
{
    add(Point{p.x-w,p.y-h});
}

void Arc::draw_lines() const
{
    if (color().visibility())
    {
        fl_arc(point(0).x, point(0).y, width+width, height+height, start, end);
    }
}
