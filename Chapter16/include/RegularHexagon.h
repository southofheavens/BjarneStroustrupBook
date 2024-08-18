// for ex04

#include "Graph.h"

using namespace Graph_lib;

struct RegularHexagon : Shape
{
    RegularHexagon(Point p, int R);
    
    void draw_lines() const;

private:
    int radius;
};
