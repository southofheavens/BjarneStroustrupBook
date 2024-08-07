/*
    Нарисуйте свои инициалы высотой 150 пикселей. Используйте толстую линию. Нарисуйте  каждый инициал
    другим цветом.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 400, "ex03");

    Open_polyline surname;
    surname.add({150,100});
    surname.add({200,100});
    surname.add({150,250});
    surname.add({200,250});
    surname.set_style(Line_style(Line_style::solid, 4));
    surname.set_color(Color::red);
    win.attach(surname);

    Open_polyline name;
    name.add({300, 100});
    name.add({250, 175});
    name.add({300, 175});
    name.add({250, 250});
    name.set_style(Line_style(Line_style::solid, 4));
    name.set_color(Color::yellow);
    win.attach(name);

    Open_polyline patronymic;
    patronymic.add({400, 100});
    patronymic.add({350, 175});
    patronymic.add({400, 175});
    patronymic.add({350, 250});
    patronymic.set_style(Line_style(Line_style::solid, 4));
    patronymic.set_color(Color::magenta);
    win.attach(patronymic);

    win.wait_for_button();
    return 0;
}
