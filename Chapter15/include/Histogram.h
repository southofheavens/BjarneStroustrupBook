#include "Graph.h"

using namespace Graph_lib;

class Histogram : public Shape
{
public:
    Histogram(Point p, unsigned int w, unsigned int h) : width{w}, height{h}
    {
        add(p);
    }
    
    void SetValues(unsigned int n); // Функция для заполнения вектора data значениями
    
    void draw_lines() const;
private:
    unsigned int width;
    unsigned int height;
    vector<double> data;
};
