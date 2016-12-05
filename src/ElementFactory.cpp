#include <typeinfo>
#include "Number.hpp"
#include "ElementFactory.hpp"

using namespace std;

Element *ElementFactory::createElement(Element *e)
{
    if (auto n = dynamic_cast<Number *>(e))
	return new Number(n->getNum());

    delete e;
}
