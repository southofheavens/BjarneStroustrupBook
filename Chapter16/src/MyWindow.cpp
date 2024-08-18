#include "../include/MyWindow.h"

MyWindow::MyWindow(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    NextButtonPushed{false},
    QuitButton{Point{x_max()-70,0},70,20,"Quit",
    [](Address, Address pw)
    {
        reference_to<MyWindow>(pw).Quit();
    }},
    NextButton{Point{x_max()-141,0},70,20,"Next",
    [](Address, Address pw)
    {
        reference_to<MyWindow>(pw).Next();
    }}
{
    attach(QuitButton);
    attach(NextButton);
}

void MyWindow::WaitForPushNext()
{
    while (!NextButtonPushed)
    {
        Fl::wait();
    }
    NextButtonPushed = false;
    Fl:redraw();
}
