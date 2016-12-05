#include "algo.hpp"

namespace algo
{
	void replace(State::iterator it, unique_ptr<Element> e)
	{
		*it = move(e);
	}

	void swap(State::iterator first, State::iterator second)
	{
		std::swap(*first,*second);
	}

	
}