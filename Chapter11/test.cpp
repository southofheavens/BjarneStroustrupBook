#include <iostream>

int main()
{
    for (int i = 0; i < 256; ++i)
    {
        std::cout << (char)i << ' ' << i << '\n';
    }
}