/*
    Нарисуйте пять олимпийских колец. Если вы не помните их цвета, найдите их в Интернете.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 400, "ex08");

    Circle blue{Point{150, 150}, 50};
    blue.set_color(Color::blue);
    blue.set_style(Line_style(Line_style::solid, 4));
    win.attach(blue);

    Circle black{Point{260, 150}, 50};
    black.set_color(Color::black);
    black.set_style(Line_style(Line_style::solid, 4));
    win.attach(black);

    Circle red{Point{370,150}, 50};
    red.set_color(Color::red);
    red.set_style(Line_style(Line_style::solid, 4));
    win.attach(red);

    Circle yellow{Point{205, 200}, 50};
    yellow.set_color(Color::yellow);
    yellow.set_style(Line_style(Line_style::solid, 4));
    win.attach(yellow);

    Circle green{Point{315, 200}, 50};
    green.set_color(Color::green);
    green.set_style(Line_style(Line_style::solid, 4));
    win.attach(green);

    win.wait_for_button();
    return 0;
}
