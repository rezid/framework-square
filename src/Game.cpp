#include "Game.hpp"
#include "Element.hpp"
#include "Cmd.hpp"

using namespace z;
using namespace std;

/* Lire les commentaires dans Game.hpp pour toute information sur
    ses fonctions */

Game::Game(int mm, int nn, ElementPtr e0)
{
    default_element = move(e0);
    m = mm;
    n = nn;

    grid.resize(m);
    for (auto &v : grid)
    {
        v.resize(n);
        for (auto &e : v)
            e = default_element->make_copy();
    }
}

bool Game::start()
{
    start_grid();

    int status = 2;

    while (status == 2)
    {
        display_grid();
        command_press();
        logic_flow();
        status = if_win_or_lose();
    }

    return status;
}
