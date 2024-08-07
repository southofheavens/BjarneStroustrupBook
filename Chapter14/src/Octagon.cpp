#include "../include/Octagon.h"
#include <cmath>

Octagon::Octagon(Point p, int R) : nearRadius{R}
{
    side = nearRadius * sqrt(2 - sqrt(2));
    insideRadius = (side * (sqrt(2) + 1)) / 2;
    add({p.x - insideRadius, p.y - insideRadius});
}

void Octagon::draw_lines() const
{
    if (color().visibility())
    {
        fl_color(color().as_int());
        // Верхняя линия
        fl_line(point(0).x + int(side/sqrt(2)), point(0).y,
                point(0).x + int(side/sqrt(2)) + side, point(0).y);
        // Левая линия
        fl_line(point(0).x, point(0).y + int(side/sqrt(2)),
                point(0).x, point(0).y + int(side/sqrt(2)) + side);
        // Нижняя линия
        fl_line(point(0).x + int(side/sqrt(2)), point(0).y + side + 2*int(side/sqrt(2)),
                point(0).x + int(side/sqrt(2)) + side, point(0).y + side + 2*int(side/sqrt(2)));
        // Правая линия
        fl_line(point(0).x + side + 2*int(side/sqrt(2)), point(0).y + int(side/sqrt(2)),
                point(0).x + side + 2*int(side/sqrt(2)), point(0).y + side + int(side/sqrt(2)));
        // Соединяет левую и верхнюю линии
        fl_line(point(0).x, point(0).y + int(side/sqrt(2)),
                point(0).x + int(side/sqrt(2)), point(0).y);
        // Соединяет левую и нижнюю линии
        fl_line(point(0).x, point(0).y + int(side/sqrt(2)) + side,
                point(0).x + int(side/sqrt(2)), point(0).y + side + 2*int(side/sqrt(2)));
        // Соединяет правую и нижнюю линии
        fl_line(point(0).x + side + 2*int(side/sqrt(2)), point(0).y + side + int(side/sqrt(2)),
                point(0).x + side + int(side/sqrt(2)), point(0).y + side + 2*int(side/sqrt(2)));
        // Соединяет правую и верхнюю линии
        fl_line(point(0).x + side + int(side/sqrt(2)), point(0).y,
                point(0).x + side + 2*int(side/sqrt(2)), point(0).y + int(side/sqrt(2)));
    }
        
    if (fill_color().visibility())
    {
        fl_color(fill_color().as_int());
        
        Polygon p;
        p.add({point(0).x + 1, point(0).y + int(side/sqrt(2)) + 1});
        p.add({point(0).x + int(side/sqrt(2)) + 1, point(0).y + 1});
        p.add({point(0).x + int(side/sqrt(2)) + side - 1, point(0).y + 1});
        p.add({point(0).x + 2*int(side/sqrt(2)) + side - 1, point(0).y + int(side/sqrt(2)) + 1});
        p.add({point(0).x + 2*int(side/sqrt(2)) + side - 1, point(0).y + int(side/sqrt(2)) + side - 1});
        p.add({point(0).x + int(side/sqrt(2)) + side - 1, point(0).y + 2*int(side/sqrt(2)) + side - 1});
        p.add({point(0).x + int(side/sqrt(2)) + 1, point(0).y + 2*int(side/sqrt(2)) + side - 1});
        p.add({point(0).x + 1, point(0).y + int(side/sqrt(2)) + side - 1});
        p.set_color(fill_color().as_int());
        p.set_fill_color(fill_color().as_int());
        p.draw_lines();
        
        fl_color(color().as_int());    // reset color
    }
}
