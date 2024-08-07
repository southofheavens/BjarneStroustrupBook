#include "include/Window.h"
#include "include/Graph.h"

constexpr unsigned int X_MAX = 600;     // Размер окна
constexpr unsigned int Y_MAX = 400;
                                        // Расстояния:
constexpr unsigned int X_OFFSET = 100;  //   от левого края до оси y
constexpr unsigned int Y_OFFSET = 60;   //   от нижнего края до оси x

constexpr unsigned int X_SPACE = 40;    // Пространство за осями
constexpr unsigned int Y_SPACE = 40;
                                        // Длины осей
constexpr unsigned int X_LENGTH = X_MAX - X_OFFSET - X_SPACE;
constexpr unsigned int Y_LENGTH = Y_MAX - Y_OFFSET - Y_SPACE;
                            
constexpr unsigned int BASE_YEAR = 1960;
constexpr unsigned int END_YEAR = 2040;
                                        // Масштабирующие множители
constexpr double X_SCALE = (double)X_LENGTH / (END_YEAR - BASE_YEAR);
constexpr double Y_SCALE = (double)Y_LENGTH / 100;

using namespace Graph_lib;

struct Distribution
{
    int year, young, middle, old;
};

istream& operator>>(istream& is, Distribution& d)
    // Предполагаемый формат: ( год : дети взрослые старики )
{
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;
    
    if (is >> ch1 >> dd.year
            >> ch2 >> dd.young >> dd.middle >> dd.old
            >> ch3)
    {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')')
        {
            is.clear(ios_base::failbit);
            return is;
        }
    }
    else
    {
        return is;
    }
    d = dd;
    return is;
}

class Scale         // Класс для преобразования координат
{
    int cbase;      // Координатная база
    int vbase;      // База значений
    double scale;
public:
    Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s} {}
    int operator()(int v) const { return cbase + (v-vbase)*scale; } // См. раздел 21.4
};

int main()
{
    Graph_lib::Window win{{100,100},X_MAX,Y_MAX,"Example from section 15.6"};
    
    std::string fileName = "japanese-age-data.txt";
    ifstream ifs;
    ifs.open(fileName);
    
    Scale xs{X_OFFSET, BASE_YEAR, X_SCALE};
    Scale ys{Y_MAX - Y_OFFSET, 0, -Y_SCALE};
    
    Axis x{Axis::x, Point{X_OFFSET, Y_MAX - Y_OFFSET}, X_LENGTH,
        (END_YEAR - BASE_YEAR) / 10,
        "year     1960        1970          1980         1990         "
        "2000        2010         2020         2030         2040"};
    x.label.move(-100,0);
    
    Axis y{Axis::y, Point{X_OFFSET, Y_MAX - Y_OFFSET}, Y_LENGTH, 10,
        "% of population"};
    
    Line currentYear{Point{xs(2008),ys(0)}, Point{xs(2008),ys(100)}};
    currentYear.set_style(Line_style::dash);
    
    Open_polyline children;
    Open_polyline adults;
    Open_polyline aged;
    
    for (Distribution d; ifs>>d; )
    {
        if (d.year < BASE_YEAR || END_YEAR < d.year)
        {
            error("Год вне диапазона");
        }
        if (d.young + d.middle + d.old != 100)
        {
            error("Проценты не согласуются");
        }
        const int x = xs(d.year);
        children.add(Point{x,ys(d.young)});
        adults.add(Point{x,ys(d.middle)});
        aged.add(Point{x,ys(d.old)});
    }
    
    Text childrenLabel{Point{20,children.point(0).y}, "age 0-14"};
    children.set_color(Color::red);
    childrenLabel.set_color(Color::red);
    
    Text adultsLabel{Point{20,adults.point(0).y}, "age 15-64"};
    adults.set_color(Color::blue);
    adultsLabel.set_color(Color::blue);
    
    Text agedLabel{Point{20,aged.point(0).y}, "age 65+"};
    aged.set_color(Color::dark_green);
    agedLabel.set_color(Color::dark_green);
    
    win.attach(children);
    win.attach(adults);
    win.attach(aged);
    
    win.attach(childrenLabel);
    win.attach(adultsLabel);
    win.attach(agedLabel);
    
    win.attach(x);
    win.attach(y);
    win.attach(currentYear);
    
    gui_main();
    ifs.close();
    return 0;
}
