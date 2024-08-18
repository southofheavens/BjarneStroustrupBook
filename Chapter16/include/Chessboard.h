#include "MyWindow.h"

class Chessboard : public MyWindow
{
public:
    Chessboard(Point xy, int w, int h, const string& title);

private:
    // Виджеты
    Out_box CoordBox; // Окно для вывода центра нажатой клеткки
    Vector_ref<Button> buttons; // Кнопки
    Vector_ref<Rectangle> cells; // Шахматные клетки
    
    void GetCellXY(Point p);
    
    // Действия, инициируемые обратными вызовами:
    void A4() { GetCellXY(buttons[0].loc); }
    void B4() { GetCellXY(buttons[1].loc); }
    void C4() { GetCellXY(buttons[2].loc); }
    void D4() { GetCellXY(buttons[3].loc); }
    void A3() { GetCellXY(buttons[4].loc); }
    void B3() { GetCellXY(buttons[5].loc); }
    void C3() { GetCellXY(buttons[6].loc); }
    void D3() { GetCellXY(buttons[7].loc); }
    void A2() { GetCellXY(buttons[8].loc); }
    void B2() { GetCellXY(buttons[9].loc); }
    void C2() { GetCellXY(buttons[10].loc); }
    void D2() { GetCellXY(buttons[11].loc); }
    void A1() { GetCellXY(buttons[12].loc); }
    void B1() { GetCellXY(buttons[13].loc); }
    void C1() { GetCellXY(buttons[14].loc); }
    void D1() { GetCellXY(buttons[15].loc); }
};
