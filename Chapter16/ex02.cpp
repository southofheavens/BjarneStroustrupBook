/*
    Создайте окно (на основе класса My_window) с шахматной доской 4x4 из квадратных кнопок. После щелчка
    на кнопке должно выполниться простое действие, например вывод ее координат в окно вывода или изменение
    ее цвета (пока не будет выполнен щелчок на другой кнопке).

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex02.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/MyWindow.cpp src/Chessboard.cpp
*/

#include "include/Chessboard.h"

int main()
{
    Chessboard chess{{100,100},600,600,"ex02"};
    
    return gui_main();
}
