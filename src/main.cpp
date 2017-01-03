#include <iostream>

#include "lib.hpp"
#include "Game_2048.hpp"
#include "Blank.hpp"
#include "Cmd.hpp"

using namespace z;

/* Exemple d'implementation du jeux 2048 basique en utilisant les fonctionalités de notre lib.
   tout commence par la création d'une classe Game_2048 qui herite de notre class Game (representant la lib)' */
   
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
