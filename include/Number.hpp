#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "lib.hpp"
#include "Element.hpp"

/* Classe principale abstraite d'un element de la grille qui represente un nombre, on herite de cette classe
 pour crée un nouveau type d'element a nombre. regarder l'exmple d'imlementation 
 du jeux 2048: la classe Power_of_2 */
class z::Number : public z::Element
{
	public:
		int num; // Le numero de l'element
		virtual ElementPtr make_copy() = 0;
};

#endif