#ifndef POWER_OF_2_HPP
#define POWER_OF_2_HPP

#include "lib.hpp"
#include "Number.hpp"

/* Classe qui represente un element de la grille du jeux 2048 et de ses variant: 
l'element:  nombre puissance de 2 */

class z::Power_of_2 : public z::Number
{
  public:
    static int temp;  

    Power_of_2(int n)  { num = 2 * n; printable = std::to_string(num); }
    virtual ElementPtr make_copy(); // fonction pour copier un element
    virtual ElementPtr merge(Element *e, z::Element_type t = z::Element_type::ELEMENT); // pour fusionner deux elements entre eux 
    virtual bool is_equal(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT); // pour comparer deux element entre eux 
    virtual bool is_greater(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT); // pour comparer deux element entre eux 
    virtual z::Element_type get_type(); // utile pour eviter le dynamique_cast
};


#endif