// for ex04

#include "GUI.h"

using namespace Graph_lib;

class RegularTriangle : public Shape
{
public:
    RegularTriangle(Point p, int r);

    void draw_lines() const;

private:
    int nearRadius;
    int insideRadius;
    int side;
};
