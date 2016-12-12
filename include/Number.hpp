#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "lib.hpp"
#include "Element.hpp"

class z::Number : public z::Element
{
	public:
		int num;
		virtual ElementPtr make_copy() = 0;
};

#endif