#ifndef LIB_HPP
#define LIB_HPP

#include <memory>
#include <vector>

/* L'espace de nom z de notre library pour eviter les collisions de nom
   on regroupe ainsi tout les classes, et fonctions dans cette espace de nom,
   On a donc un appercu de notre bibiotheque */

namespace z
{

// La position dans notre grille
struct Indice
{
    int i;
    int j;
};

// un enum qui regroupe le nom de classe des elements de la grille, utile pour eviter le dynamique_cast
enum class Element_type
{
    ELEMENT,
    BLANK,
    POWER_OF_2
};

// Les classes principale de la library
class Game;
class Cmd;
class Element;
class Blank;
class Number;
class Power_of_2;

// using directive, pour ecrire moins
using ElementPtr = std::unique_ptr<Element>;
using Grid = std::vector<std::vector<ElementPtr>>;
using CmdPtr = std::unique_ptr<Cmd>;
using Line_iterator = Grid::iterator;
using Element_iterator = std::vector<ElementPtr>::iterator;
using Reverse_element_iterator = std::vector<ElementPtr>::reverse_iterator;


/* Algorithme standard deja implementer utile pour passer dans un jeux d'un round a un autre
Pour l'instant qontient les algorithme necessaire pour le jeux de 2048 et de ses
variantes */
ElementPtr merge(Element *e0, Element *e1); 
bool is_equal(Element *e0, Element *e1);
bool is_greater(Element *e0, Element *e1);
void push_left(Grid& grid, Element_type brush);
void push_right(Grid& grid, Element_type brush);
void push_up(Grid& grid, Element_type brush);
void push_down(Grid& grid, Element_type brush);
void merge_left(Grid& grid, Element* fill);
void merge_right(Grid& grid, Element* fill);
void merge_up(Grid& grid, Element* fill);
void merge_down(Grid& grid, Element* fill);
void fill_with(Grid &grid, Element* fill);
z::Indice random_element(Grid& grid, z::Element_type type);

}

#endif