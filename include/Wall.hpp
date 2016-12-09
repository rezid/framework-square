#ifndef WALL_HPP
#define WALL_HPP

class Comparator_abstract;
#include "Element.hpp"

class Wall : public Element
{
  public:
    Wall(Comparator_abstract &c);
    virtual bool compare(Element *e);
};

#endif