#include "../include/RegularHexagon.h"
#include <cmath>

RegularHexagon::RegularHexagon(Point p, int R) : radius{R}
{
    add(p);
}

void RegularHexagon::draw_lines() const
{
    
    int r = radius * sqrt(3) / 2;
    Polygon p;
    p.add({point(0).x + radius, point(0).y}); // Правый угол
    p.add({point(0).x + radius / 2, point(0).y - r}); // Правый верхний угол
    p.add({point(0).x - radius / 2, point(0).y - r}); // Левый верхний угол
    p.add({point(0).x - radius, point(0).y}); // Левый угол
    p.add({point(0).x - radius / 2, point(0).y + r}); // Левый нижний угол
    p.add({point(0).x + radius / 2, point(0).y + r}); // Правый нижний угол
    
    if (fill_color().visibility()) // fill
    {
        int intColor = fill_color().as_int();
        p.set_fill_color(intColor);
    }
    p.draw_lines();
}
