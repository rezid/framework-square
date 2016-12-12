#ifndef POWER_OF_2_HPP
#define POWER_OF_2_HPP

#include "lib.hpp"
#include "Number.hpp"

class z::Power_of_2 : public z::Number
{
  public:
    static int temp;

    Power_of_2(int n)  { num = 2 * n; printable = std::to_string(num); }
    virtual ElementPtr make_copy();
    virtual ElementPtr merge(Element *e, z::Element_type t = z::Element_type::ELEMENT);
    virtual bool is_equal(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT);
    virtual bool is_greater(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT);

    virtual z::Element_type get_type();
};


#endif