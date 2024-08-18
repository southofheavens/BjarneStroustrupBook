#include "GUI.h"    
#include <unistd.h> // для Unix систем (для функции sleep())

using namespace Graph_lib;

struct MyWindow : Graph_lib::Window
{
    MyWindow(Point xy, int w, int h, const string& title);
    
    void WaitForPushNext();
        
protected:
    Button NextButton;
    
private:
    // Данные
    bool NextButtonPushed;

    // Виджеты
    Button QuitButton;
    
    // Действия, инициируемые обратными вызовами
    void Quit() { hide(); exit(0); }
    void Next() { NextButtonPushed = true; }
};
