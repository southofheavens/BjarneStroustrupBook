// for drill

#include "GUI.h"

using namespace Graph_lib;

struct LinesWindow : Graph_lib::Window
{
    LinesWindow(Point xy, int w, int h, const std::string& title);
    
private:
    // Данные:
    Open_polyline lines;
    
    // Виджеты:
    Button NextButton; // Добавляет пару (next_x, next_y) в объект Lines
    Button QuitButton; // Завершает работу программы
    In_box NextX;
    In_box NextY;
    Out_box XYout;
    Menu ColorMenu;
    Button ColorButton;
    Menu StyleMenu;
    Button StyleButton;
    
    void ChangeColor(Color c) { lines.set_color(c); }
    void ChangeStyle(Line_style s) { lines.set_style(s); }
    
    void HideColorMenu() { ColorMenu.hide(); ColorButton.show(); }
    void HideStyleMenu() { StyleMenu.hide(); StyleButton.show(); }
    
    // Действия, инициируемые обратными вызовами:
    void red_pressed() { ChangeColor(Color::red); HideColorMenu(); }
    void blue_pressed() { ChangeColor(Color::blue); HideColorMenu(); }
    void black_pressed() { ChangeColor(Color::black); HideColorMenu(); }
    void ColorMenuPressed() { ColorButton.hide(); ColorMenu.show(); }
    void dot_pressed() { ChangeStyle(Line_style::dot); HideStyleMenu(); }
    void dash_pressed() { ChangeStyle(Line_style::dash); HideStyleMenu(); }
    void solid_pressed() { ChangeStyle(Line_style::solid); HideStyleMenu(); }
    void StyleMenuPressed() { StyleButton.hide(); StyleMenu.show(); }
    void Next();
    void Quit();
};
