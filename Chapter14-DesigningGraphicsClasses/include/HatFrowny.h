// for ex01

#include "Frowny.h"

class HatFrowny : public Frowny
{
public:
    using Frowny::Frowny;
    
    void draw_lines() const;
};

