/*
    Выведите на экран фотографию вашего друга. Напишите его имя в заголовке окна и в заголовке внутри окна.
*/

#include "include/Simple_window.h"
#include "include/Graph.h"

int main()
{
    using namespace Graph_lib;
    Simple_window win({100,100}, 600, 400, "Meni");

    win.wait_for_button();
    return 0;
}
