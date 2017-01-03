#include "Cmd.hpp"
#include "Element.hpp"

using namespace z;

/* Lire les commentaires dans Cmd.hpp pour toute information sur
    ses fonctions */

Cmd::Cmd(Fun f, Grid *g) : grid{g}, action{f} {}

Cmd& Cmd::operator=(Cmd cmd)
{
	action = cmd.action;
	grid = cmd.grid;

	return *this;
}

void Cmd::operator()() 
{ 
	action(grid); 
}
