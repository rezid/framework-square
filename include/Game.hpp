#ifndef GAME_HPP
#define GAME_HPP

#include "lib.hpp"
#include "Cmd.hpp"

/* Classe principale abstraite de notre lib. Pour crée un jeux, il faut commancer
 par herité de cette classe. Regarder l'exemple: Game_2048.hpp et Game_2048.cpp
 pour savoir comment on utilise la class Game */

class z::Game
{
  public:
    int n; // Nombre de colonne de la grille
    int m; // Nombre de ligne de la grille
    z::Grid grid; // la grille de dimention n * m
    z::Grid bgrid; // une grille backup pour une future fonctionalité pas encore implementé
    z::ElementPtr default_element; // Represente l'element par defaut de la grille (generalement Blank)
	z::Cmd command; // Represente la commande envoyé a la grille (exemple: deplacer tout les elements a droit)

    Game(int n_line, int n_colomn, z::ElementPtr brush); // Constructeur appelé par les classes hérités pour construire la grille

    /* La boucle principale du jeux, pour un jeux simple, on devrait laisser le comportement par defaut 
    qui est :
       etape1 : etat initiale de la grille (exemple jeux 2048: 2 elements dans la grille) 
       etape2 : afficher la grille 
       etape3 : commande crée (exemple jeux 2048: touche z presser) 
       etape4 : commande traité (exemple jeux 2048: avancer tout les elements de la grille vers le haut) 
       etape5 : est-ce-que on a gangné ou perdu ?
       etape6 : revenir vers etape 2 */
    bool start();


    virtual void start_grid() = 0;    // crée l'etat initial de la grille
	virtual void display_grid() = 0;  // afficher la grille
	virtual void command_press() = 0; // crée une commande
	virtual void logic_flow() = 0;    // traiter la commande
	virtual int if_win_or_lose() = 0; // verifier si on a gagner ou perdu ou continuer
	
};

#endif