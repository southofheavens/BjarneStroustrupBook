// for ex01

#include "Smiley.h"

class HatSmiley : public Smiley
{
public:
    using Smiley::Smiley;
    
    void draw_lines() const;
};
