// for ex01

#include "Graph.h"

using namespace Graph_lib;

struct Arc : Shape 
{
    // p - центр эллипса, w - ширина, h - высота, s и e задают угол (от 0 до 360)
    Arc(Point p, int w, int h, int s, int e);

    void draw_lines() const;

private:
    int width;
    int height;
    int start;
    int end;
};
