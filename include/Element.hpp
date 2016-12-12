#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include "lib.hpp"
#include <string>

class z::Element
{
  public:
    virtual ElementPtr make_copy() = 0;

    virtual ElementPtr merge(Element *e, z::Element_type t = z::Element_type::ELEMENT) { return nullptr; }
    
    virtual bool is_equal(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT) { return true; }
    virtual bool is_greater(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT) { return true; }

    virtual z::Element_type get_type() {return z::Element_type::ELEMENT;}

    std::string printable;
};

#endif