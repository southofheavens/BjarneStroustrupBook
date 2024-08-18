#include "../include/LinesWindow.h"

LinesWindow::LinesWindow(Point xy, int w, int h, const std::string& title)
    : Graph_lib::Window{xy, w, h, title},
    NextButton{Point{x_max()-150,0}, 70, 20, "Next point",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).Next();
        }},
    QuitButton{Point{x_max()-70,0}, 70, 20, "Quit",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).Quit();
        }},
    NextX{Point{x_max()-310,0}, 50, 20, "next x:"},
    NextY{Point{x_max()-210,0}, 50, 20, "next y:"},
    XYout{Point{100,0}, 100, 20, "current (x,y):"},
    ColorMenu{Point{x_max()-80,30}, 80, 20, Menu::vertical, "color"},
    ColorButton{Point{x_max()-80,30}, 80, 20, "color menu",
    [] (Address, Address pw)
    {
        reference_to<LinesWindow>(pw).ColorMenuPressed();
    }},
    StyleMenu{Point{300,30}, 70, 20, Menu::horizontal, "style"},
    StyleButton{Point{300,30}, 80, 20, "style menu",
    [] (Address, Address pw)
    {
        reference_to<LinesWindow>(pw).StyleMenuPressed();
    }}
{
    attach(NextButton);
    attach(QuitButton);
    attach(NextX);
    attach(NextY);
    attach(XYout);
    XYout.put("no point");
    ColorMenu.attach(new Button{Point{0,0},0,0,"red",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).red_pressed();
        }});
    ColorMenu.attach(new Button{Point{0,0},0,0,"blue",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).blue_pressed();
        }});
    ColorMenu.attach(new Button{Point{0,0},0,0,"black",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).black_pressed();
        }});
    attach(ColorMenu);
    ColorMenu.hide();
    attach(ColorButton);
    StyleMenu.attach(new Button{Point{0,0},0,0,"dot",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).dot_pressed();
        }});
    StyleMenu.attach(new Button{Point{0,0},0,0,"dash",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).dash_pressed();
        }});
    StyleMenu.attach(new Button{Point{0,0},0,0,"solid",
        [] (Address, Address pw)
        {
            reference_to<LinesWindow>(pw).solid_pressed();
        }});
    attach(StyleMenu);
    StyleMenu.hide();
    attach(StyleButton);
    attach(lines);
}

void LinesWindow::Quit()
{
    hide();
}

void LinesWindow::Next()
{
    int x = NextX.get_int();
    int y = NextY.get_int();
    lines.add(Point{x,y});
    
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    XYout.put(ss.str());
    
    redraw();
}
