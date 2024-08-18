#include "../include/Fctn.h"

void Fctn::Reset()
{    
    if (r2-r1<=0) error("Неверный диапазон");
    if (count<=0) error("Неположительное значение count");
    double dist = (r2-r1)/count;
    double r = r1;
    for (int i = 0; i < count; ++i)
    {
        Shape::set_point(i, Point{orig.x+int(r*xscale), orig.y-int(f(r)*yscale)});
        r += dist;
    }
}

void Fctn::SetFunction(Fct* ff)
{
    f = ff;
    Reset();
}

void Fctn::SetRange(double rr1, double rr2)
{
    r1 = rr1;
    r2 = rr2;
    Reset();
}

void Fctn::SetOrig(Point o)
{
    orig = o;
    Reset();
}

void Fctn::SetCount(int c)
{
    count = c;
    Reset();
}

void Fctn::SetScale(int x, int y)
{
    xscale = x;
    yscale = y;
    Reset();
}
