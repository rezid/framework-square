#ifndef CMD_HPP
#define CMD_HPP

#include <functional>
#include "lib.hpp"

using Fun = std::function<void(z::Grid*)>;

/* Classe qui represente une commande envoyer a la grille,
 Regarder l'exmple de jeux 2048 : la class Game_2048 pour savoir comment l'utiliser */

class z::Cmd
{
  public:
    Cmd(Fun action, Grid* g); // Crée une commande avec la fonction a executer et la grille en parametre
	Cmd& operator=(Cmd cmd); 
	Cmd() {}
    void operator()();


    Grid* grid;
    Fun action;
};

#endif