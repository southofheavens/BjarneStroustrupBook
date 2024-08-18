#include "MyWindow.h"

class ImageButtonWin : public MyWindow
{
public:
    ImageButtonWin(Point xy, int w, int h, const string& title);

private:
    // Данные
    Image Cat;
    int x;
    int y;
    
    // Виджеты
    Button But;
    
    // Действия, инициируемые обратными вызовами
    void Move();
};
