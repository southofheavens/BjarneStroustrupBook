#include "../include/RegularTriangle.h"

RegularTriangle::RegularTriangle(Point p, int r) : nearRadius{r}
{
    add(p);
    side = sqrt(3)*nearRadius;
    insideRadius = side*sqrt(3)/6;
}

void RegularTriangle::draw_lines() const
{
    if (color().visibility())
    {
        Closed_polyline Triangle;
        Triangle.add({point(0).x,point(0).y - nearRadius});
        Triangle.add({point(0).x - side / 2,point(0).y+insideRadius});
        Triangle.add({point(0).x + side / 2,point(0).y+insideRadius});
        Triangle.draw_lines();
    }
}
