#ifndef GAME_HPP
#define GAME_HPP

#include "lib.hpp"
#include "Cmd.hpp"

class z::Game
{
  public:
    int n; // nombre de colonne
    int m; // nombre de ligne
    z::Grid grid;
    z::Grid bgrid;
    z::ElementPtr default_element;

	z::Cmd command;

    Game(int n_line, int n_colomn, z::ElementPtr brush);

    virtual void start_grid() = 0;
	virtual void display_grid() = 0;
	virtual void command_press() = 0;
	virtual void logic_flow() = 0;
	virtual int if_win_or_lose() = 0;
	bool start();
};

#endif