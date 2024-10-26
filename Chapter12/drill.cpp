/*
 * Задание
 *
 * Это задание - графический эквивалент простейшей программы "Hello, World!" Его цель - ознакомить вас
 * с простейшими графическими средствами.
 *
 * 1. Напишите программу, создающую пустое окно Simple_window размером 600x400 пикселей с меткой My window,
 * скомпилируйте ее, скомпонуйте и выполните. Помните о том, что вы должны подключить библиотеку FLTK,
 * описанную в приложении Г, включить в свой код заголовочные файлы Graph.h и Simple_window.h, а также
 * включить в проект файлы Graph.cpp и Window.cpp
 * 2. Добавьте по одному примеры из раздела 12.7, выполняя тестирование после каждого добавленного подраздела.
 * 3. Выполните программу, внеся небольшие изменения (например, измените цвет, местоположение фигур или
 * количество точек) в каждом из примеров.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * drill.cpp src/Window.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp
 */

#include "include/Graph.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{100,100},600,400,"My window"};
    
    Axis xa{Axis::x, Point(20, 300), 150, 6, "x axis"}; // Создаем объект Axis
    // Класс Axis - разновидность класса Shape
    // Axis::x означает горизонтальную ось
    // Начало оси - в точке (20,300)
    // Длина оси - 280 пикселей
    // Ось содержит 10 делений
    // "Ось x" - метка оси
    win.attach(xa); // Связываем объект xa с окном win

    Axis ya{Axis::y, Point{20, 300}, 250, 10, "y axis"};
    ya.set_color(Color::red); // Выбираем цвет
    ya.label.set_color(Color::dark_red); // Выбираем цвет текста
    win.attach(ya);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50}; // График синуса
    // Рисуем sin в диапазоне [0,100) от (0,0) до (20,150),
    // Используя 1000 точек; для масштабирования коордианты
    // Умножаются на 50 каждая
    sine.set_color(Color::green); // Мы изменили цвет графика синуса
    win.attach(sine);

    Polygon poly; // Polygon - разновидность Shape
    poly.add(Point{300, 200}); // Три точки образуют треугольник
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::yellow);
    poly.set_style(Line_style::dashdot);
    poly.set_style(Line_style(Line_style::dash, 4));
    win.attach(poly);

    Rectangle r{Point{200,200}, 100, 50}; // Левый верхний угол, ширина, высота
    r.set_fill_color(Color::blue); // Цвет внутри прямоугольника
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    // Фактически изображение объекта poly_rect на экране является прямоугольником.
    // Однако объект класса Closed_polyline (в книге написано poly_rect, видимо, опечатка)
    // в памяти не является объектом класса Rectangle и ничего не "знает" о прямоугольниках.
    // Проще всего это доказать, попытавшись добавить новую точку.
    poly_rect.add(Point{50, 75});
    // Прямоугольник не может состоять из пяти точек.
    poly_rect.set_style(Line_style(Line_style::dot, 2));
    poly_rect.set_fill_color(Color::dark_magenta);
    win.attach(poly_rect);

    Text t(Point{150, 150}, "Hello, graphical world!");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    Image ii{Point{100, 50}, "resources/image.jpg"}; // Файл 400x212 пикселей
    ii.move(100, 200);
    win.attach(ii); // в формате jpg

    // Приведем еще один фрагмент кода без объяснений
    Circle c{Point{520, 80}, 50};
    Ellipse e{Point{520, 80}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m{Point{520, 80}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};

    Image cal{Point{225, 225}, "resources/snow_cpp.gif"}; // 320*240 пикселей, формат gif
    cal.set_mask(Point{40, 40}, 200, 150); // Вывод центральной части рисунка

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.wait_for_button(); // Вывод на экран
    
    return 0;
}
