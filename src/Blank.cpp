#include "Blank.hpp"
#include "Power_of_2.hpp"
#include "lib.hpp"

using namespace z;

ElementPtr Blank::make_copy()
{
	return ElementPtr(new Blank());
}

ElementPtr Blank::merge(Element *e, Element_type t)
{
	if (t == Element_type::ELEMENT) {
        return e->merge(this, Element_type::BLANK);
    }
    else if (t == Element_type::POWER_OF_2) {
        return ElementPtr(new Power_of_2(Power_of_2::temp));
    }
    else if (t == Element_type::BLANK) {
        return ElementPtr(new Blank());
    }
    else
        return nullptr;
}

bool Blank::is_equal(Element *e, bool& out, Element_type t)
{

    if (t == Element_type::ELEMENT) {
        return e->is_equal(this, out, Element_type::BLANK);
    }
    else if (t == Element_type::POWER_OF_2) {
        out = false;
        return false;
    }
    else if (t == Element_type::BLANK) {
        out = false;
        return false;
    }
    else
        return true;    
};

bool Blank::is_greater(Element* e, bool& out, Element_type t)
{
    if (t == Element_type::ELEMENT) {
        return e->is_greater(this, out, Element_type::BLANK);
    }
    else if (t == Element_type::POWER_OF_2) {
        out = true;
        return false;
    }
    else if (t == Element_type::BLANK) {
        out = false;
        return false;
    }
    else
        return true;
}

Element_type Blank::get_type() { return Element_type::BLANK; };