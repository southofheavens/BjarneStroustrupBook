/*
    Ниже перечислено множество пар, составленных из роста и количества людей указанного роста (с точностью
    до пяти сантиметров): (170,7), (175,9), (180,23), (190,6), (195,1). Как изобразить эти данные? Если
    вы не нашли лучшего решения, постройте гистограмму. Помните об осях и метках. Запишите данные в файл и
    считайте их оттуда.

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex08.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
*/

#include "include/Window.h"
#include "include/Pie.h"

// Размер окна
constexpr unsigned int X_MAX = 800; 
constexpr unsigned int Y_MAX = 600;

// Ширина и высота прямоугольника, описанного около окружности
constexpr unsigned int PIE_WIDTH = X_MAX / 2;  
constexpr unsigned int PIE_HEIGHT = X_MAX / 2; 

// Координаты x и y верхнего левого угла прямоугольника, описанного около окружности
constexpr unsigned int X_PIE = X_MAX / 8;
constexpr unsigned int Y_PIE = X_MAX / 8;
const Point PIE_COORDS = {X_PIE, Y_PIE};

// Ширина и высота прямоугольников, нарисованных справа от круга
constexpr unsigned int RECT_WIDTH = X_MAX / 20;
constexpr unsigned int RECT_HEIGHT = Y_MAX / 20;
constexpr unsigned int RECT_X = X_MAX - X_MAX / 4; // Координата x верхнего левого угла прямоугольника

int main()
{
    Graph_lib::Window win{{100,100},X_MAX,Y_MAX,"ex08"};

    vector<unsigned int> growths {170, 175, 180, 185, 190, 195};
    vector<unsigned int> quantities {7, 9, 23, 17, 6, 1};
    unsigned int sumOfQuantities = 0;
    for (unsigned int quantity : quantities)
    {
        sumOfQuantities += quantity;
    }

    unsigned int startAngle = 0;
    unsigned int endAngle = (double)quantities[0] / sumOfQuantities * 360;
    Vector_ref<Pie> pies;

    int rectY = Y_MAX / 6; // Координата y верхнего левого угла прямоугольника
    Vector_ref<Rectangle> rectangles;
    Vector_ref<Text> texts;

    Text title{{X_MAX / 3,Y_MAX / 10}, "Рост и количество людей заданного роста"};
    title.set_font_size(X_MAX / 60);
    win.attach(title);

    for (int i = 0; i < quantities.size(); ++i)
    {
        // Рисуем "кусочек пирога"
        pies.push_back(new Pie{PIE_COORDS, PIE_WIDTH, PIE_HEIGHT, startAngle, endAngle});
        pies[i].set_fill_color(Color(i + 1));
        win.attach(pies[i]);

        // Рисуем прямоугольник с необходимым цветом и текст
        rectangles.push_back(new Rectangle{{RECT_X, rectY}, RECT_WIDTH, RECT_HEIGHT});
        rectangles[i].set_fill_color(Color(i + 1));
        win.attach(rectangles[i]);

        ostringstream ss;
        ss << '(' << growths[i] << ',' << quantities[i] << ')';
        texts.push_back(new Text{{RECT_X + RECT_WIDTH + RECT_WIDTH / 2, rectY + (int)RECT_HEIGHT / 2}, ss.str()});
        win.attach(texts[i]);

        if (i != quantities.size() - 1)
        {
            startAngle = endAngle;
            endAngle += (double)quantities[i + 1] / sumOfQuantities * 360;
            rectY += Y_MAX / 8;
            if (i == quantities.size() - 2) 
            // Устраняем оставшееся пространство, которое образовалось из-за преобразований чисел типа,
            // double в тип int, чтобы круг включал в себя 360 градусов
            {
                endAngle += 360 - endAngle;
            }
        }
    }

    gui_main();
    return 0;
}
