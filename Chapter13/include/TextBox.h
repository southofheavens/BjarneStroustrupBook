// for ex06

#include "Box.h"
#include <string>

struct TextBox : Shape
{
    TextBox(Point p, int w, int h, std::string t);
    
    void draw_lines() const;
    
private:
    int width;
    int height;
    std::string text;
};
