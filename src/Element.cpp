#include "Element.hpp"

#include "Comparator_abstract.hpp"

Element::Element(Comparator_abstract &c) { comparator = &c; }
bool Element::compare(Element *e)
{
    return comparator->compare_element_with_element(this, e);
    
}
