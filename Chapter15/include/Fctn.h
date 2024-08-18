// for ex02

#include "Graph.h"

using namespace Graph_lib;

// Fct -> Fctn

class Fctn : public Function
{
public:
    Fctn(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25) :
        Function(f, r1, r2, orig, count, xscale, yscale), f{f}, r1{r1}, r2{r2}, orig{orig}, count{count},
        xscale{xscale}, yscale{yscale} { }
    
    void SetFunction(Fct ff);
    void SetRange(double rr1, double rr2);
    void SetOrig(Point o);
    void SetCount(int c);
    void SetScale(int x, int y);
    
private:
    Fct* f;
    double r1;
    double r2;
    Point orig;
    int count;
    double xscale;
    double yscale;
    void Reset();
};
