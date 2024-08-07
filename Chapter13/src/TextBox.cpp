#include "../include/TextBox.h"

TextBox::TextBox(Point p, int w, int h, std::string t) : width{w}, height{h}, text{t}
{
    add(p);
}

void TextBox::draw_lines() const
{
    Box b{point(0), width, height};
    b.draw_lines();
    
    Text t
    {
        {
            point(0).x + width / 2 - (int)text.length() * 4,
            point(0).y + height / 2 + height / 10
        },
        text
    };
    t.draw_lines();
}
