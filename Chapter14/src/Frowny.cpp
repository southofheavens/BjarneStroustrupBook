#include "../include/Frowny.h"

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
