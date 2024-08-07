/*
    Определите класс Group, служащий контейнером объектов класса Shape с соответствующими операциями над
    членами класса Group. Указание: Vector_ref. Используя класс Group, определите класс, рисующий шахматную
    доску, по которой под управлением программы могут перемещаться шашки.
 
    Я не очень понял тз, а конкретно при чём здесь вообще шахматная доска и зачем для передвижения шашек нам
    реализовывать класс Group, если шашки (объекты класса Circle) можно просто хранить в Vector_ref и при
    необходимости обращаться к любому объекту, поэтому я просто реализую класс Group, ко всем объектам которого
    будет применяться соответствующая операция.
*/

#include "include/Simple_window.h"
#include "include/Group.h"
#include "include/Octagon.h"

int main()
{
    Simple_window win{{100,100},600,400,"ex09"};
    
    Group gr;
    
    Rectangle r({100,100},200,100);
    win.attach(r);
    gr.add(r);
    
    Circle c{{150,150},50};
    win.attach(c);
    gr.add(c);
    
    Octagon o{{250,250},50};
    win.attach(o);
    gr.add(o);
    
    win.wait_for_button();
    gr.move(15,15);
    
    win.wait_for_button();
    gr.set_color(Color::red);
    
    win.wait_for_button();
    gr.set_style(2);
    
    win.wait_for_button();
    gr.set_fill_color(Color::white);
        
    win.wait_for_button();
    return 0;
}
