#include "../include/ch14tools.h"

// --------------------------------- for ex01

void Smiley::draw_lines() const
{
    Circle::draw_lines();
    fl_arc(point(0).x + Circle::radius() / 2,         // Улыбка
           point(0).y + Circle::radius() * 12 / 10,
           Circle::radius(), Circle::radius() / 2,
           180, 360);
    fl_arc(point(0).x + Circle::radius() / 2,         // Левый глаз
           point(0).y + Circle::radius() / 2,
           Circle::radius() / 3, Circle::radius() / 3,
           0, 360);
    fl_arc(point(0).x + Circle::radius() * 7 / 6,     // Правый глаз
           point(0).y + Circle::radius() / 2,
           Circle::radius() / 3, Circle::radius() / 3,
           0, 360);
    fl_pie(point(0).x + Circle::radius() * 7 / 12,    // Левый зрачок
           point(0).y + Circle::radius() * 7 / 12,
           Circle::radius() / 6, Circle::radius() / 6,
           0, 360);
    fl_pie(point(0).x + Circle::radius() * 15 / 12,   // Правый зрачок
           point(0).y + Circle::radius() * 7 / 12,
           Circle::radius() / 6, Circle::radius() / 6,
           0, 360);
}

void Frowny::draw_lines() const
{
    Circle::draw_lines();
    fl_arc(point(0).x + Circle::radius() / 2,         // НЕ Улыбка
           point(0).y + Circle::radius() * 12 / 10,
           Circle::radius(), Circle::radius() / 2,
           0, 180);
    fl_arc(point(0).x + Circle::radius() / 2,         // Левый глаз
           point(0).y + Circle::radius() / 2,
           Circle::radius() / 3, Circle::radius() / 3,
           0, 360);
    fl_arc(point(0).x + Circle::radius() * 7 / 6,     // Правый глаз
           point(0).y + Circle::radius() / 2,
           Circle::radius() / 3, Circle::radius() / 3,
           0, 360);
    fl_pie(point(0).x + Circle::radius() * 7 / 12,    // Левый зрачок
           point(0).y + Circle::radius() * 7 / 12,
           Circle::radius() / 6, Circle::radius() / 6,
           0, 360);
    fl_pie(point(0).x + Circle::radius() * 15 / 12,   // Правый зрачок
           point(0).y + Circle::radius() * 7 / 12,
           Circle::radius() / 6, Circle::radius() / 6,
           0, 360);
}

void HatSmiley::draw_lines() const
{
    Smiley::draw_lines();
    fl_color(10);
    fl_pie(point(0).x - Circle::radius() / 5,       // Основание шляпы
           point(0).y - Circle::radius() / 10,
           Circle::radius() * 12 / 5, Circle::radius() / 2,
           0,360);
    fl_rectf(point(0).x + Circle::radius() / 3,
             point(0).y - Circle::radius() / 2,
             Circle::radius() * 4 / 3,
             Circle::radius() / 2);
}

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

// --------------------------------- for ex04

void ImmobileCircle::move(int dx, int dy) { }

// --------------------------------- for ex05

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

// --------------------------------- for ex08

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
