/*
    Нарисуйте двумерный дом анфас, как это делают дети: дверь, два окна и крыша с дымовой
    трубой. Детали можете выбрать сами, можете даже нарисовать дымок из трубы.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 400, "ex07");

    Rectangle house({150,200},300,150); // Дом
    house.set_fill_color(Color::yellow);
    win.attach(house);

    Polygon roof; // Крыша
    roof.add({150,200});
    roof.add({450,200});
    roof.add({300,100});
    roof.set_fill_color(Color::red);
    win.attach(roof);

    Rectangle door({265,230},70,120); // Дверь
    door.set_fill_color(Color::dark_yellow);
    win.attach(door);

    Line doorKnob({320,295}, {328,295}); // Дверная ручка
    doorKnob.set_style(Line_style(Line_style::solid, 3));
    win.attach(doorKnob);

    Rectangle firstWindow({175,245},70,70); // Левое окно
    firstWindow.set_fill_color(Color::cyan);
    win.attach(firstWindow);

    Open_polyline fwLines; // Линии на левом окне
    fwLines.add({210,245});
    fwLines.add({210,315});
    fwLines.add({210,280});
    fwLines.add({245,280});
    win.attach(fwLines);

    Rectangle secondWindow({355,245},70,70); // Правое окно
    secondWindow.set_fill_color(Color::cyan);
    win.attach(secondWindow);

    Open_polyline swLines; // Линии на правом окне
    swLines.add({390,245});
    swLines.add({390,315});
    swLines.add({390,280});
    swLines.add({425,280});
    win.attach(swLines);

    Rectangle mainChimney({335,110},55,65); // Основная часть дымовой трубы
    mainChimney.set_fill_color(Color::dark_red);
    win.attach(mainChimney);

    Rectangle topOfChimney({330,100},65,10); // Верхушка дымовой трубы
    topOfChimney.set_fill_color(Color::dark_red);
    win.attach(topOfChimney);

    win.wait_for_button();
    return 0;
}
