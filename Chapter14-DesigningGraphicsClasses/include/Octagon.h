// for ex08

#include "Graph.h"

using namespace Graph_lib;

class Octagon : public Shape
{
public:
    Octagon(Point c, int R); // c - центр восьмиугольника, R - расстояние от центра до угла
    
    int GetInside() { return insideRadius; }
    
    void draw_lines() const;
    
private:
    int nearRadius;     // Радиус описанной окружности
    int insideRadius;   // Радиус вписанной окружности
    int side;           // Длина стороны восьмиугольника
};
