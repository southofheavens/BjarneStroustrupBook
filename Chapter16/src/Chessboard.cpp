#include "../include/Chessboard.h"

Chessboard::Chessboard(Point xy, int w, int h, const string& title) 
: MyWindow{xy, w, h, title},
CoordBox({160,0},80,20,"Центр нажатой клетки:")
{
    NextButton.hide();
    
    // Четвертая линия
    buttons.push_back(new Button{Point{100,100},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).A4();}});
    buttons.push_back(new Button{Point{200,100},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).B4();}});
    buttons.push_back(new Button{Point{300,100},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).C4();}});
    buttons.push_back(new Button{Point{400,100},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).D4();}});
    
    // Третья линия
    buttons.push_back(new Button{Point{100,200},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).A3();}});
    buttons.push_back(new Button{Point{200,200},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).B3();}});
    buttons.push_back(new Button{Point{300,200},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).C3();}});
    buttons.push_back(new Button{Point{400,200},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).D3();}});
    
    // Вторая линия
    buttons.push_back(new Button{Point{100,300},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).A2();}});
    buttons.push_back(new Button{Point{200,300},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).B2();}});
    buttons.push_back(new Button{Point{300,300},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).C2();}});
    buttons.push_back(new Button{Point{400,300},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).D2();}});
    
    // Первая линия
    buttons.push_back(new Button{Point{100,400},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).A1();}});
    buttons.push_back(new Button{Point{200,400},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).B1();}});
    buttons.push_back(new Button{Point{300,400},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).C1();}});
    buttons.push_back(new Button{Point{400,400},100,100,"", [](Address, Address pw){
        reference_to<Chessboard>(pw).D1();}});
    
    // Шахматные клетки
    unsigned int cellIndex = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cells.push_back(new Rectangle{Point{100+j*100,100+i*100},100,100});
            (i + j) % 2 == 0 ? cells[cellIndex].set_fill_color(Color::white)
                : cells[cellIndex].set_fill_color(Color::black);
            attach(cells[cellIndex]); // Связываем с окном клетку
            cellIndex++;
        }
    }
    
    // Связываем с окном оставшиеся объекты
    for(int i = 0; i < buttons.size(); ++i)
    {
        attach(buttons[i]);
    }
    attach(CoordBox);
    CoordBox.put("(-,-)");
}

void Chessboard::GetCellXY(Point p)
{
    ostringstream ss;
    ss << '(' << p.x + 50 << ',' << p.y + 50 << ')';
    CoordBox.put(ss.str());
}
