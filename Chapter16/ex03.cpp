/*
    Разместите объект класса Image поверх объекта класса Button; после щелчка на кнопке переместите оба объекта.
    Для выбора нового местоположения "кнопки с изображением" используйте следующий генератор случайных чисел
    из std_lib_facilities.h:
    #include<random>
    inline int rand_int(int min, int max)
    {
        static default_random_engine ran;
        return uniform_int_distribution<>(min,nax)(ran);
    }
    Эта функция возвращает случайное целое число в диапазоне [min,max).

    How to compile:
    clang++ -std=c++11 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex03.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp src/MyWindow.cpp src/ImageButtonWin.cpp
*/

#include "include/ImageButtonWin.h"

int main()
{
    ImageButtonWin win{{100,100},800,600,"ex03"};
    
    return gui_main();
}
