#include "../include/Arrow.h"
#include <cmath>

void Arrow::draw_lines() const
{
    constexpr double PI = 3.14159265;
    
    int diffX = point(1).x - point(0).x;
    int diffY = point(1).y - point(0).y;
    double angle = atan2(diffY, diffX) * 180 / PI;
    
    double x1 = point(1).x - cos((angle - iso) * PI / 180) * size;
    double y1 = point(1).y - sin((angle - iso) * PI / 180) * size;
    
    double x2 = point(1).x - cos((angle + iso) * PI / 180) * size;
    double y2 = point(1).y - sin((angle + iso) * PI / 180) * size;
    
    Polygon head;
    head.add(point(1));
    head.add({(int)x1,(int)y1});
    head.add({(int)x2,(int)y2});
    head.set_fill_color(color());
    
    head.draw_lines();
    Shape::draw_lines();
}
