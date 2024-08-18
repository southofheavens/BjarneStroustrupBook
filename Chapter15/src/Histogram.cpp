#include "../include/Histogram.h"

void Histogram::SetValues(unsigned int n)
{
    double value;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        data.push_back(value);
    }
}

void Histogram::draw_lines() const
{
    Axis x{Axis::x, {point(0).x, point(0).y + (int)height}, (int)width, 0};
    Axis y{Axis::y, {point(0).x, point(0).y + (int)height}, int(height), 10};
    x.draw_lines();
    y.draw_lines();
    
    double max = 0;
    for (double value : data)
    {
        if (value > max)
        {
            max = value;
        }
    }
    ostringstream ss;
    ss << max;
    Text maxValue{{point(0).x - 5, point(0).y - 5}, ss.str()};
    maxValue.draw_lines();
    
    int distance = (double)width / data.size() / 5; // Расстояние между колоннами
    int widthOfColumn = width / data.size() - distance; // Ширина колонны
    int xColumn = point(0).x + distance; // Координата x колонны
    
    Vector_ref<Rectangle> columns;
    for (int i = 0; i < data.size(); ++i)
    {
        int heightOfColumn = data[i] / max * height; // Высота колонны
        int yColumn = point(0).y + height - heightOfColumn; // Координата y колонны
        columns.push_back(new Rectangle{{xColumn, yColumn},widthOfColumn,heightOfColumn});
        columns[i].set_fill_color(Color::dark_green);
        columns[i].draw_lines();
        xColumn = xColumn + widthOfColumn + distance;
    }
}
