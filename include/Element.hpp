#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "lib.hpp"
#include <string>

/* Classe principale abstraite d'un element de la grille, on herite de cette classe
 pour crée un nouveau type d'element. regarder l'exmple d'imlementation 
 du jeux 2048: les classes: Blank, Number et Power_of_2' */

class z::Element
{
  public:
    std::string printable; // utile pour du debug et pour tester de nouvelle idée

    virtual ElementPtr make_copy() = 0;  // pour dupliquer un element (chauqe element a sa logique)

    /* Pour fusionner deux elements entre eux, cette fonction est trés importantes, regarder les exemples d'implementation
    de merge dans la classe Blank, Number et Power_of_2 pour comprendre comment on devrait l'utiliser*/
    virtual ElementPtr merge(Element *e, z::Element_type t = z::Element_type::ELEMENT) { return nullptr; }
    
    /* Pour comparer les elements entre eux, egarder les exemples d'implementation
    dans la classe Blank, Number et Power_of_2 */
    virtual bool is_equal(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT) { return true; }
    virtual bool is_greater(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT) { return true; }

    /* Trés utile pour eviter le dynamique_cast qui degrade les performances */
    virtual z::Element_type get_type() {return z::Element_type::ELEMENT;}
};

#endif