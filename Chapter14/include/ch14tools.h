#include "Graph.h"
#include <cmath>  // for ex08

using namespace Graph_lib;

// --------------------------------- for ex01

class Smiley : public Circle
{
public:
    using Circle::Circle;
    
    void draw_lines() const;
};

class Frowny : public Circle
{
public:
    using Circle::Circle;
    
    void draw_lines() const;
};

class HatSmiley : public Smiley
{
public:
    using Smiley::Smiley;
    
    void draw_lines() const;
};

class HatFrowny : public Frowny
{
public:
    using Frowny::Frowny;
    
    void draw_lines() const;
};

// --------------------------------- for ex04

class ImmobileCircle : public Circle
{
public:
    using Circle::Circle;
    
    void move(int dx, int dy);
};

// --------------------------------- for ex05

class StripedRectangle : public Rectangle
{
    using Rectangle::Rectangle;
    
    void draw_lines() const;
};

// --------------------------------- for ex08

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
