#include "Wall.hpp"

#include "Comparator_abstract.hpp"

Wall::Wall(Comparator_abstract &c) : Element(c) {}
bool Wall::compare(Element *e)
{
    comparator->compare_wall_with_element(this, e);
    return true;
}
