#include "../include/Arc.h"

Arc::Arc(Point p, int w, int h, int s, int e) : width{w}, height{h}, start{s}, end{e}
{
    add(Point{p.x-w,p.y-h});
}

void Arc::draw_lines() const
{
    if (color().visibility())
    {
        fl_color(color().as_int());
        fl_arc(point(0).x, point(0).y, width+width, height+height, start, end);
    }
    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
        fl_pie(point(0).x+1, point(0).y+1, width+width-2, height+height-2, start, end);
        fl_color(color().as_int());    // reset color
    }
}
