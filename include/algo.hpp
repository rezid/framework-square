#ifndef STATE_H
#define STATE_H
#include "State.hpp"
#endif


class Element;

namespace algo
{
	void replace(State::iterator it, unique_ptr<Element> elem);
	void swap(State::iterator first, State::iterator second);
}