#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "Comparator_abstract.hpp"

class Comparator : public Comparator_abstract
{
  public:
    virtual bool compare_number_with_element(Number *n, Element *e1);
    virtual bool compare_number_with_number(Number *n, Number *e1);
    virtual bool compare_number_with_wall(Number *n, Wall *e1);

    virtual bool compare_wall_with_element(Wall *w, Element *e1);
    virtual bool compare_wall_with_wall(Wall *w, Wall *e1);

    virtual bool compare_wall_with_number(Wall *w, Number *e1);

    virtual bool compare_element_with_element(Element *e0, Element *e1);
};

#endif