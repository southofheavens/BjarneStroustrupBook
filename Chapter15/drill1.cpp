/*
    Первая часть

    Задание:
    Задание, связанное с построением графиков.
    1. Создайте пустое окно 600x600 с меткой "Графики функций".
    2. Обратите внимание, что вам надо создать проект, свойства которого указаны на веб-сайте в примечании
    к руководству по инсталляции библиотеки FLTK.
    3. Поместите файлы Graph.cpp и Window.cpp в свой проект. (Находятся в папке src)
    4. Добавьте оси x и y длиной по 400 пикселей с метками "1 == 20 пикселей" и делениями через каждые
    20 пикселей. Оси должны пересекаться в точке (300,300).
    5. Сделайте обе оси красными.
    
    В дальнейшем используйте отдельный объект класса Shape для построения каждой из перечисленных ниже функций.
    1. Постройте график функции double one(double x){return 1;} в диапазоне [-10;11] с началом координат (0,0)
    в точке (300,300), используя 400 точек и не выполняя масштабирования (в окне).
    2. Измените рисунок, применив масштабирование с коэффициентом 20 как по оси x, так и по оси y.
    3. В дальнейшем используйте этот диапазон и коэффициенты масштабирования при построении всех графиков.
    4. Добавьте график функции double slope(double x){return x/2;}
    5. Пометьте наклонную линию с помощью объекта класса Text со значением "x/2" в точке, расположенной
    прямо над левым нижним углом окна.
    6. Добавьте график функции double square(double x){return x*x;}
    7. Добавьте график косинуса (не создавая новую функцию).
    8. Сделайте график косинуса синим.
    9. Напишите функцию sloping_cos(), суммирующую косинус и функцию slope() (как определено выше) и добавьте
    в окно ее график.
 
    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    drill1.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
*/

#include "include/Window.h"
#include "include/Graph.h"

constexpr unsigned int X_MAX = 600; // Размер окна
constexpr unsigned int Y_MAX = 600;

constexpr unsigned int DIVISION_SCALE = 20; // Размер одного деления

constexpr unsigned int X_ORIG = X_MAX / 2; // Центр окна
constexpr unsigned int Y_ORIG = Y_MAX / 2;
const Point ORIG{X_ORIG, Y_ORIG};

constexpr unsigned int X_LENGTH = 400; // Длины осей
constexpr unsigned int Y_LENGTH = 400;

constexpr int R_MIN = -10; // Диапазон
constexpr int R_MAX = 11;

constexpr unsigned int N_POINTS = 400; // Количество точек в диапазоне

double One(double){return 1;}
double Slope(double x){return x/2;}
double Square(double x){return x*x;}
double SlopingCose(double x){return cos(x) + Slope(x);}

int main()
{
    Graph_lib::Window win{{100,100},X_MAX,Y_MAX,"Графики функций"};
    
    using namespace Graph_lib;
    
    Axis x{Axis::x, Point{(X_MAX - X_LENGTH) / 2, Y_ORIG},
        X_LENGTH, X_LENGTH / DIVISION_SCALE, "1 == 20 пикселей"};
    x.set_color(Color::red);
    Axis y{Axis::y, Point{X_ORIG, Y_LENGTH + (Y_MAX - Y_LENGTH) / 2},
        Y_LENGTH, Y_LENGTH / DIVISION_SCALE, "1 == 20 пикселей"};
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
    
    Function f1{One, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Function f2{Slope, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Text label{{100,425}, "x/2"};
    Function f3{Square, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    Function f4{[](double x){return cos(x);},
        R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    f4.set_color(Color::blue);
    Function f5{SlopingCose, R_MIN, R_MAX, ORIG, N_POINTS, DIVISION_SCALE, DIVISION_SCALE};
    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);
    
    gui_main();
    return 0;
}
