#include "Power_of_2.hpp"
#include "lib.hpp"

using namespace z;

int Power_of_2::temp = 0;

ElementPtr Power_of_2::make_copy()
{
    return ElementPtr(new Power_of_2(num));
}

ElementPtr Power_of_2::merge(Element *e, Element_type t)
{
    if (t == Element_type::ELEMENT)
    {
        temp = num;
        return e->merge(this, Element_type::POWER_OF_2);
    }
    else if (t == Element_type::POWER_OF_2)
    {
        return ElementPtr(new Power_of_2(num));
    }
    else
        return nullptr;
}

bool Power_of_2::is_equal(Element *e, bool &out, Element_type t)
{
    if (t == Element_type::ELEMENT)
    {
        temp = num;
        return e->is_equal(this, out, Element_type::POWER_OF_2);
    }
    else if (t == Element_type::POWER_OF_2)
    {
        out = (num == temp);
        return false;
    }
    else
        return true;
}

bool Power_of_2::is_greater(Element* e, bool& out, Element_type t)
{
    if (t == Element_type::ELEMENT)
    {
        temp = num;
        return e->is_greater(this, out, Element_type::POWER_OF_2);
    }
    else if (t == Element_type::POWER_OF_2)
    {
        out = ( temp > num );
        return false;
    }
    else
        return true;
}

Element_type Power_of_2::get_type() { return Element_type::POWER_OF_2; };