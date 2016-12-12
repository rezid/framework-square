#include <iostream>

#include "lib.hpp"
#include "Game_2048.hpp"
#include "Blank.hpp"
#include "Cmd.hpp"

using namespace z;

int main()
{
    ElementPtr brush = ElementPtr(new Blank());

    bool restart = false;

    do
    {
        Game_2048 game(6, 4, brush->make_copy(), 128);
        restart = game.start();
    }
    while ( restart );

    return 0;
}
