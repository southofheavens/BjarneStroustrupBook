// for ex04

#include "Graph.h"

using namespace Graph_lib;

class ImmobileCircle : public Circle
{
public:
    using Circle::Circle;
    
    void move(int dx, int dy) {}
};
