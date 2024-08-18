#include "../include/ImageButtonWin.h"

ImageButtonWin::ImageButtonWin(Point xy, int w, int h, const string& title)
: MyWindow(xy,w,h,title),
Cat{{0,0},"include/cat.jpg"},
But{{0,0},110,110,"",[](Address, Address pw){
    reference_to<ImageButtonWin>(pw).Move();}}
{
    NextButton.hide();
    attach(But);
    attach(Cat);
}

void ImageButtonWin::Move()
{
    x = randint(0,690);
    y = randint(0,490);
    Cat.move(x-Cat.point(0).x,y-Cat.point(0).y);
    But.move(x-But.loc.x,y-But.loc.y);
    redraw();
}
