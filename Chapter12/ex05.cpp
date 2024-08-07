/*
    Нарисуйте красную рамку шириной полсантиметра вокруг прямоугольника, высота которого составляет
    три четверти высоты вашего экрана, а ширине - две трети ширины экрана.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 900;

int main()
{
    using namespace Graph_lib;
    Simple_window win({0, 0}, SCREEN_WIDTH, SCREEN_HEIGHT, "ex05");

    Rectangle r
    (
    {((SCREEN_WIDTH - (SCREEN_WIDTH / 3 * 2)) / 2),
    ((SCREEN_HEIGHT - (SCREEN_HEIGHT / 4 * 3)) / 2)},
    SCREEN_WIDTH / 3 * 2, 
    SCREEN_HEIGHT / 4 * 3
    );
    win.attach(r);

    Rectangle frame
    (
    {((SCREEN_WIDTH - (SCREEN_WIDTH / 3 * 2)) / 2 - 11),
    ((SCREEN_HEIGHT - (SCREEN_HEIGHT / 4 * 3)) / 2) - 11},
    SCREEN_WIDTH / 3 * 2 + 22, 
    SCREEN_HEIGHT / 4 * 3 + 22
    );
    frame.set_style(Line_style(Line_style::solid, 20));
    frame.set_color(Color::red);
    win.attach(frame);

    win.wait_for_button();
    return 0;
}
