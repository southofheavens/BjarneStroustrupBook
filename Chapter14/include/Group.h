// for ex09

#include "Graph.h"

using namespace Graph_lib;

class Group : public Shape
{
public:
    Group() {}
    
    void add(Shape& s);
    void move(int dx, int dy) override;
    void set_color(Color col);
    void set_style(Line_style sty);
    void set_fill_color(Color col);
private:
    Vector_ref<Shape> vr;
};
