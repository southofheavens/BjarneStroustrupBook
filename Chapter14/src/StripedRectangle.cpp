#include "../include/StripedRectangle.h"

void StripedRectangle::draw_lines() const
{
    if (color().visibility()) // lines on top of fill
    {
        fl_color(color().as_int());
        fl_rect(point(0).x,point(0).y,width(),height());
    }
    
    if (fill_color().visibility()) // fill
    {
        fl_color(fill_color().as_int());
        
        // Штриховка
        for (int i = 5; i < height(); i+=5)
        {
            fl_line_style(0, 2);
            fl_line(point(0).x, point(0).y + i, point(0).x + width(), point(0).y + i);
            fl_line_style(0);
        }
        
        fl_color(color().as_int());    // reset color
    }
}
