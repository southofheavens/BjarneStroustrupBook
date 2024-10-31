/*
 * Напишите программу, рисующую диаграмму классов, подобную изображенной в разделе 12.6. Программировать
 * будет проще, если начать с определения класса Box, объект которого представляет собой прямоугольник
 * с текстовой меткой.
 * 
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * ex06.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp \
 * src/Arrow.cpp src/Box.cpp src/TextBox.cpp
 */

#include "include/Simple_window.h"
#include "include/Arrow.h"
#include "include/TextBox.h"

int main()
{
    Simple_window win{{100,100},520,300,"ex06"};
    
    TextBox Window{{100,100},60,20,"Window"};
    win.attach(Window);
    
    TextBox Simple_window{{70,150},120,20,"Simple_window"};
    win.attach(Simple_window);
    
    Arrow fromSWtoW{{130,150},{130,120}};
    win.attach(fromSWtoW);
    
    TextBox Line_Style{{180,100},90,20,"Line_style"};
    win.attach(Line_Style);
    
    TextBox Color{{290,100},60,20,"Color"};
    win.attach(Color);
    
    TextBox Shape{{220,140},70,20,"Shape"};
    win.attach(Shape);
    
    TextBox Point{{360,160},60,20,"Point"};
    win.attach(Point);
    
    TextBox Line{{55,220},40,20,"Line"};
    win.attach(Line);
    
    Arrow fromLineToShape{{75,220},{220,160}};
    win.attach(fromLineToShape);
    
    TextBox Lines{{105,220},50,20,"Lines"};
    win.attach(Lines);
    
    Arrow fromLinesToShape{{130,220},{235,160}};
    win.attach(fromLinesToShape);
    
    TextBox Polygon{{165,220},60,20,"Polygon"};
    win.attach(Polygon);
    
    Arrow fromPolygonToShape{{195,220},{245,160}};
    win.attach(fromPolygonToShape);
    
    TextBox Axis{{235,220},40,20,"Axis"};
    win.attach(Axis);
    
    Arrow fromAxisToShape{{255,220},{255,160}};
    win.attach(fromAxisToShape);
    
    TextBox Rectangle{{285,220},80,20,"Rectangle"};
    win.attach(Rectangle);
    
    Arrow fromRectangleToShape{{325,220},{265,160}};
    win.attach(fromRectangleToShape);
    
    TextBox Text{{375,220},40,20,"Text"};
    win.attach(Text);
    
    Arrow fromTextToShape{{395,220},{275,160}};
    win.attach(fromTextToShape);
    
    TextBox Image{{425,220},50,20,"Image"};
    win.attach(Image);
    
    Arrow fromImageToShape{{450,220},{290,160}};
    win.attach(fromImageToShape);
    
    win.wait_for_button();
    return 0;
}
