#include "MyWindow.h"
#include "RegularHexagon.h"
#include "RegularTriangle.h"

using namespace Graph_lib;

class ShapeWindow : public MyWindow
{
public:
    ShapeWindow(Point xy, int w, int h, const string& title);
    
private:
    // Данные
    int x;
    int y;
    Circle c;
    Rectangle r;
    RegularTriangle rt;
    RegularHexagon rh;
    
    // Виджеты
    Menu ShapeMenu;
    Button Circle;
    Button Square;
    Button Triangle;
    Button Hexagon;
    In_box CoordsBox;
    
    void GetCoords();
    
    // Действия, инициируемые обратными вызовами
    void DrawCircle();
    void DrawSquare();
    void DrawTriangle();
    void DrawHexagon();
};
