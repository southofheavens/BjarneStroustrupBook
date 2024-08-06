#include "../include/Box.h"

Box::Box(Point p, int w, int h) : width{w}, height{h} 
    {
        if (w % 10 != 0 || h % 10 != 0)
        {
            throw std::invalid_argument("Значения width и height должны быть кратны 10!");
        }

        if (width > height)
        {
            diameter = width / 10;
        }
        else
        {
            diameter = height / 10;
        }

        radius = (double)diameter / 2;

        add(p);
    }

void Box::draw_lines() const
{
    if (color().visibility())
    {
        fl_line(point(0).x, point(0).y + radius - EMPTINESS,                // Левая линия
                point(0).x, point(0).y + height - radius + EMPTINESS); 
        fl_line(point(0).x + radius - EMPTINESS, point(0).y,                // Верхняя линия
                point(0).x + width - radius + EMPTINESS, point(0).y); 
        fl_line(point(0).x + width, point(0).y + radius - EMPTINESS,        // Правая линия
                point(0).x + width, point(0).y + height - radius + EMPTINESS); 
        fl_line(point(0).x + radius - EMPTINESS, point(0).y + height,       // Нижняя линия
                point(0).x + width - radius + EMPTINESS, point(0).y + height); 
        
        fl_arc(point(0).x + width - diameter + EMPTINESS, point(0).y,       // Верхняя правая дуга
                diameter, diameter, 0, 90); 
        fl_arc(point(0).x, point(0).y,                                      // Верхняя левая дуга
                 diameter, diameter, 90, 180);                              
        fl_arc(point(0).x, point(0).y + height - diameter + EMPTINESS,      // Нижняя левая дуга
                 diameter, diameter, 180, 270);                             
        fl_arc(point(0).x + width - diameter + EMPTINESS, point(0).y + height - diameter + EMPTINESS, // Нижняя правая дуга
                 diameter, diameter, 270, 360);  
    }
}
