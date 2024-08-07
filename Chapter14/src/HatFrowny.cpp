#include "../include/HatFrowny.h"

void HatFrowny::draw_lines() const
{
    Frowny::draw_lines();
    fl_color(8);
    fl_pie(point(0).x - Circle::radius() / 5,       // Основание шляпы
           point(0).y - Circle::radius() / 10,
           Circle::radius() * 12 / 5, Circle::radius() / 2,
           0,360);
    fl_rectf(point(0).x + Circle::radius() / 3,
             point(0).y - Circle::radius() / 2,
             Circle::radius() * 4 / 3,
             Circle::radius() / 2);
}
