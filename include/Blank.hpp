#ifndef BLANK_HPP
#define BLANK_HPP

#include "lib.hpp"
#include "Element.hpp"

class z::Blank : public z::Element
{
	public:
		virtual ElementPtr make_copy();

		virtual ElementPtr merge(Element *e, z::Element_type t = z::Element_type::ELEMENT);
		virtual bool is_equal(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT);
		virtual bool is_greater(Element* e, bool& out, z::Element_type t = z::Element_type::ELEMENT);

		virtual z::Element_type get_type();
};

#endif