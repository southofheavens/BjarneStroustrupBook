#include "../include/Clock.h"

Clock::Clock(Point p, unsigned int r, Graph_lib::Window* w)
: Base{{p.x,p.y},(int)r},
Center{{p.x,p.y},(int)r/35},
SecondHand{{p.x,p.y},{0,0}},
MinuteHand{{p.x,p.y},{0,0}},
HourHand{{p.x,p.y},{0,0}},
win{w}
{
    Center.set_fill_color(Color::black);
    SecondHand.set_color(Color::red);
    HourHand.set_style(Line_style(Line_style::solid,3));
    add(p);
    
    int onBaseX;
    int onBaseY;
    int inBaseX;
    int inBaseY;
        
    for(int i = 0; i < 360; i+=6)
    {
        onBaseX = Base.center().x + cos(i*PI/180)*Base.radius();
        onBaseY = Base.center().y - sin(i*PI/180)*Base.radius();
        inBaseX = Base.center().x + cos(i*PI/180)*(Base.radius()-10);
        inBaseY = Base.center().y - sin(i*PI/180)*(Base.radius()-10);
        ClockDivisions.push_back(new Line{{onBaseX,onBaseY},{inBaseX,inBaseY}});
        if (i % 30 == 0)
        {
            ClockDivisions[ClockDivisions.size() - 1].set_style(Line_style(Line_style::solid, 4));
            ClockDivisions[ClockDivisions.size() - 1].set_color(28);
        }
    }
    
    UpdateTime();
    
    secondAngle = 6*seconds+90;
    minuteAngle = 6*minutes+90+(seconds/20)*2;
    hourAngle = 30*hours+90+(minutes/6)*3;
    
    SetTips();
}

void Clock::draw_lines() const
{
    Base.draw();
    Center.draw();
    for (int i = 0; i < ClockDivisions.size(); ++i)
    {
        ClockDivisions[i].draw();
    }
    MinuteHand.draw();
    SecondHand.draw();
    HourHand.draw();
}

void Clock::CbRunClock(void* p)
{
    Clock* c = (Clock*)p;
    c->RunClock();
    Fl::repeat_timeout(1.0, Clock::CbRunClock, p);
}

void Clock::RunClock()
{
    UpdateTime();
    
    secondAngle += 6;
    if (seconds % 20 == 0) { minuteAngle += 2; }
    if (minutes % 6 == 0 && seconds == 0) { hourAngle += 3; }
    
    SetTips();
    Redraw(win);
}

void Clock::Redraw(Graph_lib::Window* win)
{
    win->redraw();
}

void Clock::SetTips()
{
    SecondHand.SetTip({int(Base.center().x-cos(secondAngle*PI/180)*Base.radius()),
        int(Base.center().y-sin(secondAngle*PI/180)*Base.radius()-1)});
    
    MinuteHand.SetTip({int(Base.center().x-cos(minuteAngle*PI/180)*(Base.radius()-15)),
        int(Base.center().y-sin(minuteAngle*PI/180)*(Base.radius()-10))});
    
    HourHand.SetTip({int(Base.center().x-cos(hourAngle*PI/180)*(Base.radius()-50)),
        int(Base.center().y-sin(hourAngle*PI/180)*(Base.radius()-50))});
}

void Clock::UpdateTime()
{
    time_t now = time(NULL);
    seconds = (*localtime(&now)).tm_sec;
    minutes = (*localtime(&now)).tm_min;
    hours = (*localtime(&now)).tm_hour;
}
