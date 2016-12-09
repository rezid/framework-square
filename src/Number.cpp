#include "Number.hpp"

#include "Comparator_abstract.hpp"

Number::Number(Comparator_abstract &c) : Element(c) {}

bool Number::compare(Element *e)
{
    comparator->compare_number_with_element(this, e);
    return true;
}
bool Number::compare(Number *e)
{ 
    return true;
}
bool Number::compare(Wall *e)
{
    return true;
}
