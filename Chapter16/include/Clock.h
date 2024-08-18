#include "GUI.h"
#include "Arrow.h" // Для стрелок
#include <time.h> // Для определения текущего времени

constexpr double PI = 3.1415926;

using namespace Graph_lib;

class Clock : public Shape
{
public:
    Clock(Point p, unsigned int r, Graph_lib::Window* w);
            
    static void CbRunClock(void* p);

private:
    void draw_lines() const;

    void RunClock();
    
    void Redraw(Graph_lib::Window* win);
    
    void SetTips();
    
    void UpdateTime();
    
    Circle Base; // Основа часов
    Circle Center;
    Vector_ref<Line> ClockDivisions; // Деления на часах
    Arrow SecondHand; // Секундная стрелка
    Arrow MinuteHand; // Минутная стрелка
    Arrow HourHand; // Часовая стрелка
    Graph_lib::Window* win; // Указатель на окно, в котором будут расположены часы
    
    unsigned int seconds;
    unsigned int minutes;
    unsigned int hours;
    int secondAngle;
    int minuteAngle;
    int hourAngle;
};
