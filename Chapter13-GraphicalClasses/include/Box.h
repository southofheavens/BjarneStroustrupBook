// for ex02 and ex06

#include "Graph.h"

constexpr int EMPTINESS = 1;

using namespace Graph_lib;

struct Box : Shape
{
    Box(Point p, int w, int h); 

    void draw_lines() const;

private:
    int width;
    int height;
    int diameter;
    double radius;
};
