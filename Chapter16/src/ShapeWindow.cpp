#include "../include/ShapeWindow.h"

ShapeWindow::ShapeWindow(Point xy, int w, int h, const string& title)
: MyWindow(xy,w,h,title),
c{{x,y},100},
r{{-int(100*sqrt(2)/(double)2),-int(100*sqrt(2)/(double)2)},int(100*sqrt(2)),int(100*sqrt(2))},
rt{{x,y},100},
rh{{x,y},100},
ShapeMenu{{0,0},200,20,Menu::vertical,"Фигуры"},
Circle{{0,0},0,0,"Окружность",[](Address, Address pw){
        reference_to<ShapeWindow>(pw).DrawCircle();}},
Square{{0,0},0,0,"Квадрат",[](Address, Address pw){
        reference_to<ShapeWindow>(pw).DrawSquare();}},
Triangle{{0,0},0,0,"Равносторонний треугольник",[](Address, Address pw){
    reference_to<ShapeWindow>(pw).DrawTriangle();}},
Hexagon{{0,0},0,0,"Шестиугольник",[](Address, Address pw){
    reference_to<ShapeWindow>(pw).DrawHexagon();}},
CoordsBox{{500,0},70,20,"Введите координаты центра в формате (x,y):"}
{
    NextButton.hide();
    attach(c);
    c.set_color(Color::Transparency::invisible);
    attach(r);
    r.set_color(Color::Transparency::invisible);
    attach(rt);
    rt.set_color(Color::Transparency::invisible);
    attach(rh);
    rh.set_color(Color::Transparency::invisible);
    
    ShapeMenu.attach(Circle);
    ShapeMenu.attach(Square);
    ShapeMenu.attach(Triangle);
    ShapeMenu.attach(Hexagon);
    attach(ShapeMenu);
    attach(CoordsBox);
    
}

void ShapeWindow::GetCoords()
{
    std::string coords = CoordsBox.get_string();
    istringstream is{coords};
    char ch1;
    char ch2;
    char ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        std::cout << "Вы ввели некорректную пару координат!\n";
        Exit();
    }
}

void ShapeWindow::DrawCircle()
{
    GetCoords();
    c.set_color(Color::Transparency::visible);
    c.move(x-c.center().x,y-c.center().y);
    redraw();
}

void ShapeWindow::DrawSquare()
{
    GetCoords();
    r.set_color(Color::Transparency::visible);
    r.move(x-(r.point(0).x+int(100*sqrt(2)/(double)2)),y-(r.point(0).y+int(100*sqrt(2)/(double)2)));
    redraw();
}

void ShapeWindow::DrawTriangle()
{
    GetCoords();
    rt.set_color(Color::Transparency::visible);
    rt.move(x-rt.point(0).x,y-rt.point(0).y);
    redraw();
}

void ShapeWindow::DrawHexagon()
{
    GetCoords();
    rh.set_color(Color::Transparency::visible);
    rh.move(x-rh.point(0).x,y-rh.point(0).y);
    redraw();
}
