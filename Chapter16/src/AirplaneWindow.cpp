#include "../include/AirplaneWindow.h"

AirplaneWindow::AirplaneWindow(Point xy, int w, int h, const string& title)
: Graph_lib::Window(xy,w,h,title),
Plane{{0,y_max() / 2}, "include/airplane.jpg"},
Start{{x_max()-140,0},70,20,"Start",[](Address, Address pw){
    reference_to<AirplaneWindow>(pw).CallCbStart();}},
Stop{{x_max()-70,0},70,20,"Stop",[](Address, Address pw){
    reference_to<AirplaneWindow>(pw).CallCbStop();}}
{
    Plane.move(0,-(Plane.GetHeight() * 2 / 3));
    planeX = 1;
    attach(Start);
    attach(Stop);
    attach(Plane);
}

void AirplaneWindow::CbStartFlight(void* p)
{
    AirplaneWindow* aw = (AirplaneWindow*)p;
    aw->StartFlight();
    Fl::repeat_timeout(0.003, AirplaneWindow::CbStartFlight, p);
}

void AirplaneWindow::CallCbStart()
{
    Fl::remove_timeout(CbStartFlight);
    Fl::add_timeout(0.003, CbStartFlight, this);
}

void AirplaneWindow::CallCbStop()
{
    Fl::remove_timeout(CbStartFlight);
}

void AirplaneWindow::StartFlight()
{
    if (Plane.point(0).x >= x_max()) { Plane.move(-(Plane.point(0).x+Plane.GetWidth()),0); }
    Plane.move(planeX,0);
    redraw();
}
