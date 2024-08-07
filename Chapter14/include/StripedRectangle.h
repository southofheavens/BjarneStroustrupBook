// for ex05

#include "Graph.h"

using namespace Graph_lib;

class StripedRectangle : public Rectangle
{
    using Rectangle::Rectangle;
    
    void draw_lines() const;
};
