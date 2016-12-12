#ifndef CMD_HPP
#define CMD_HPP

#include <functional>
#include "lib.hpp"

using Fun = std::function<void(z::Grid*)>;

class z::Cmd
{
  public:
    Cmd(Fun action, Grid* g);
	Cmd& operator=(Cmd cmd);
	Cmd() {}
    void operator()();


    Grid* grid;
    Fun action;
};

#endif