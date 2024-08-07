#include "../include/Group.h"

void Group::add(Shape& s)
{
    vr.push_back(&s);
}

void Group::move(int dx, int dy)
{
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].move(dx, dy);
    }
}

void Group::set_color(Color col)
{
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].set_color(col);
    }
}

void Group::set_style(Line_style sty)
{
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].set_style(sty);
    }
}

void Group::set_fill_color(Color col)
{
    for (int i = 0; i < vr.size(); ++i)
    {
        vr[i].set_fill_color(col);
    }
}
