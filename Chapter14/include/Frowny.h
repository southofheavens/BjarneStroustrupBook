// for ex01

#include "Graph.h"

using namespace Graph_lib;

class Frowny : public Circle
{
public:
    using Circle::Circle;
    
    void draw_lines() const;
};
