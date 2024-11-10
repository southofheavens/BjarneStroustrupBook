/*
 * Определите два класса, Smiley (веселый) и Frowny (хмурый), производные от класса Circle и имеющие два глаза
 * и рот. Затем создайте классы, производные от классов Smiley и Frowny, добавляющие к каждому из них
 * соответствующую шляпу.
 */

#include "../include/Simple_window.h"
#include "../include/ch14tools.h"

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
