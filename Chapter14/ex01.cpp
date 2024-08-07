/*
    Определите два класса, Smiley (веселый) и Frowny (хмурый), производные от класса Circle и имеющие два глаза
    и рот. Затем создайте классы, производные от классов Smiley и Frowny, добавляющие к каждому из них
    соответствующую шляпу.

    How to compile:
    clang++ -std=c++20 -I/usr/local/include -L/usr/local/lib -lfltk -lfltk_images \
    ex01.cpp src/Simple_window.cpp src/Graph.cpp src/GUI.cpp src/Window.cpp \
    src/Smiley.cpp src/Frowny.cpp src/HatSmiley.cpp src/HatFrowny.cpp
*/

#include "include/Simple_window.h"
#include "include/HatSmiley.h"
#include "include/HatFrowny.h"

int main()
{
    Simple_window win{{100,100},950,400,"ex01"};
    
    Smiley s{{125,200},75};
    win.attach(s);
    
    Frowny f{{350,200},75};
    win.attach(f);
    
    HatSmiley hs{{575,200},75};
    win.attach(hs);
    
    HatFrowny hf{{800,200},75};
    win.attach(hf);
    
    win.wait_for_button();
    return 0;
}
