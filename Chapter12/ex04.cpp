/*
    Нарисуйте доску для игры в крестики-нолики размером 3x3, чередуя белые и красные квадраты.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

constexpr int SQUARE_SIZE = 49;

int main()
{
    using namespace Graph_lib;
    Simple_window win({100, 100}, 350, 350, "ex04");

    Rectangle r1({100, 100}, SQUARE_SIZE, SQUARE_SIZE);
    r1.set_color(Color::white);
    win.attach(r1);

    Rectangle r2({150, 100}, SQUARE_SIZE, SQUARE_SIZE);
    r2.set_color(Color::red);
    win.attach(r2);

    Rectangle r3({200, 100}, SQUARE_SIZE, SQUARE_SIZE);
    r3.set_color(Color::white);
    win.attach(r3);

    Rectangle r4({100, 150}, SQUARE_SIZE, SQUARE_SIZE);
    r4.set_color(Color::red);
    win.attach(r4);

    Rectangle r5({150, 150}, SQUARE_SIZE, SQUARE_SIZE);
    r5.set_color(Color::white);
    win.attach(r5);

    Rectangle r6({200, 150}, SQUARE_SIZE, SQUARE_SIZE);
    r6.set_color(Color::red);
    win.attach(r6);

    Rectangle r7({100, 200}, SQUARE_SIZE, SQUARE_SIZE);
    r7.set_color(Color::white);
    win.attach(r7);

    Rectangle r8({150, 200}, SQUARE_SIZE, SQUARE_SIZE);
    r8.set_color(Color::red);
    win.attach(r8);

    Rectangle r9({200, 200}, SQUARE_SIZE, SQUARE_SIZE);
    r9.set_color(Color::white);
    win.attach(r9);

    win.wait_for_button();
    return 0;
}
