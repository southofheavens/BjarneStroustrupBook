#include "include/Simple_window.h" // Обеспечивает доступ к оконной библиотеке
#include "include/Graph.h" // Обеспечивает доступ к графической библиотеке

int main()
{
    using namespace Graph_lib; // Графические средства находятся в Graph_lib

    Point tl{100, 100}; // Задаем левый верхний угол окна
    Simple_window win{tl, 600, 400, "Canvas #2"}; // Простое окно (Размер 600x400, Заголовок "Canvas #2")

    Axis xa{Axis::x, Point(20, 300), 280, 10, "x axis"}; // Создаем объект Axis
    // Класс Axis - разновидность класса Shape
    // Axis::x означает горизонтальную ось
    // Начало оси - в точке (20,300)
    // Длина оси - 280 пикселей
    // Ось содержит 10 делений
    // "Ось x" - метка оси
    win.attach(xa); // Связываем объект xa с окном win

    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan); // Выбираем цвет
    ya.label.set_color(Color::dark_red); // Выбираем цвет текста
    win.attach(ya);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50}; // График синуса
    // Рисуем sin в диапазоне [0,100) от (0,0) до (20,150),
    // Используя 1000 точек; для масштабирования коордианты
    // Умножаются на 50 каждая
    sine.set_color(Color::blue); // Мы изменили цвет графика синуса
    win.attach(sine); 

    Polygon poly; // Polygon - разновидность Shape
    poly.add(Point{300, 200}); // Три точки образуют треугольник
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);
    poly.set_style(Line_style(Line_style::dash, 4));
    win.attach(poly);

    Rectangle r{Point{200,200}, 100, 50}; // Левый верхний угол, ширина, высота
    r.set_fill_color(Color::yellow); // Цвет внутри прямоугольника
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
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.attach(poly_rect);

    Text t(Point{150, 150}, "Hello, graphical world!");
    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.attach(t);

    Image ii{Point{100, 50}, "image.jpg"}; // Файл 400x212 пикселей
    ii.move(100, 200);
    win.attach(ii); // в формате jpg

    // Приведем еще один фрагмент кода без объяснений
    Circle c{Point{100, 200}, 50};
    Ellipse e{Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    Mark m{Point{100, 200}, 'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};

    Image cal{Point{225, 225}, "snow_cpp.gif"}; // 320*240 пикселей, формат gif
    cal.set_mask(Point{40, 40}, 200, 150); // Вывод центральной части рисунка

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.attach(cal);
    win.wait_for_button(); // Вывод на экран
}
