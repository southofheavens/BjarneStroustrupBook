// for ex14 and ex15

#include "Graph.h"
#include <cmath>

using namespace Graph_lib;

struct RightTriangle : Shape
{
    RightTriangle(Point rightAngle, Point secondAngle, Point thirdAngle);
    
    void draw_lines() const;
};
