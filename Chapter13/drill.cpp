/*
 * Задание
 *
 * 1. Создайте простое окно Simple_window размером 800x1000 пикселей.
 * 2. Разместите сетку размером 8x8 в левой части окна размером 800x800 пикселей (так что каждый квадрат
 * сетки имеет размер 100x100 пикселей).
 * 3. Раскрасьте восемь квадратов, расположенных по диагонали, начиная с левого верхнего угла, в красный
 * цвет (используйте класс Rectangle).
 * 4. Подберите изображение размером 200x200 пикселей (в формате JPEG или GIF) и разместите три его копии
 * поверх сетки (каждое изображение покроет четыре квадрата). Если вы не найдете изображения, размеры
 * которого точно равнялись бы 200 пикселям, то, используя функцию set_mask(), вырежьте соответствующий
 * фрагмент более крупного изображения. Не закрывайте красные квадраты.
 * 5. Добавьте изображение размером 100x100 пикселей. Перемещайте его с одного квадрата на другой, щелкая
 * на кнопке Next. Для этого поместите вызов функции wait_for_button() в цикл, сопроводив его командами,
 * выбирающими новый квадрат для вашего изображения.
 *
 * How to compile:
 * clang++ -std=c++14 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
 * drill.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp
 */

#include "include/Graph.h"
#include "include/Simple_window.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win{{0,0},800,1000,"drill"};
    
    Vector_ref<Rectangle> vr;
    
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            vr.push_back(new Rectangle{{i*100,j*100},100,100});
            if (i == j) {
                vr[vr.size()-1].set_fill_color(Color::dark_red);
            }
            win.attach(vr[vr.size()-1]);
        }
    }
    
    Vector_ref<Image> vi;
    vi.push_back(new Image{{0,400},"resources/belka.jpg"});
    vi.push_back(new Image{{0,600},"resources/belka.jpg"});
    vi.push_back(new Image{{200,600},"resources/belka.jpg"});
    for (int i = 0; i < vi.size(); ++i) {
        win.attach(vi[i]);
    }
    
    int pandaX = 0;
    int pandaY = 0;
    Image panda{{100,0},"resources/panda.jpg"};
    win.attach(panda);
    
    while(true)
    {
        win.wait_for_button();
        panda.move(100, 0);
        pandaX++;
        if (pandaX == 6 - pandaY)
        {
            win.wait_for_button();
            panda.move(-pandaX*100 + 100, 100);
            pandaY++;
            pandaX = 0;
        }
        if (pandaY == 6)
        {
            win.wait_for_button();
            panda.move(-600,-600);
            pandaX = 0;
            pandaY = 0;
        }
    }
    
    return 0;
}
