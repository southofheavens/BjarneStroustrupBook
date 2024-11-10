/*
 * Определите класс Controller, содержащий четыре виртуальные функции: on(), off(), set_level(int) и
 * show(). Породите из класса Controller как минимум два класса. Один из них должен быть простым 
 * тестовым классом, в котором функция show() выводит на печать информацию о том, включен или выключен
 * контроллер, а также его текущий уровень. Второй производный класс должен управлять цветом линий
 * объекта Shape; точный смысл понятия "уровень" определите сами. Попробуйте найти третий объект для
 * управления с помощью класса Controller.
 */

#include <iostream>
#include "../include/Graph.h"
#include "../include/Simple_window.h"

class Controller
{
protected:
    bool turnOn = false;
    int level = 0;

public:
    virtual void On() { turnOn = true; }
    virtual void Off() { turnOn = false; }
    virtual void SetLevel(int l) { level = l; }
    virtual void Show() { };
};

class Test : public Controller
{
public:
    void Show() override;
};

void Test::Show()
{
    if (turnOn) {
        std::cout << "Контроллер включен!\n";
    }
    else {
        std::cout << "Контроллер выключен!\n";
    }
}

class LineColor : public Controller
{
private:
    Shape& s;

public:
    LineColor(Shape& ss) : s{ss} {}
    void SetLevel(int l) override;
};

void LineColor::SetLevel(int l)
{
    s.set_color(l);
}

int main()
{
    Test t;
    t.On();
    t.Show();
    t.Off();
    t.Show();
    
    Simple_window win{{100,100},800,600,"ex16"};

    Circle cir{{150,150},50};
    win.attach(cir);

    LineColor lc(cir);
    lc.SetLevel(5);

    win.wait_for_button();

    return 0;
}
