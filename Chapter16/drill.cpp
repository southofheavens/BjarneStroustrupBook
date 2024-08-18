/*
    Задание
    1. Создайте совершенно новый проект с настройками редактора связей для работы с библиотекой FLTK
    (описаны в приложении Г.)
    2. Используя возможности Graph_lib, введите текст программы из раздела 16.5 и заставьте ее работать.
    3. Модифицируйте программу так, чтобы она использовала всплывающее меню, описанное в разделе 16.7,
    и добейтесь ее работы.
    4. Измените программу так, чтобы в ней было второе  меню для выбора стиля линий, и добейтесь ее
    корректной работы.

    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    drill.cpp src/Window.cpp src/Graph.cpp src/GUI.cpp src/LinesWindow.cpp
*/

#include "include/LinesWindow.h"

int main()
{
    LinesWindow win{Point{100,100}, 600, 400, "lines"};
    return gui_main();
}
