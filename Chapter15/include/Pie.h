#include "Graph.h"

using namespace Graph_lib;

class Pie : public Shape
{
public:
    Pie(Point p, unsigned int w, unsigned int h,
    unsigned int a1, unsigned int a2) : width{w}, height{h}, startAngle{a1}, endAngle{a2}
    {
        add(p);
    }

    void draw_lines() const
    {
        if (fill_color().visibility()) 
        {
            fl_color(fill_color().as_int());
            fl_pie(point(0).x,point(0).y,width,height,startAngle,endAngle);
            fl_color(color().as_int());	// reset color
        }
    }

private:
    unsigned int width;
    unsigned int height;
    unsigned int startAngle;
    unsigned int endAngle;
};