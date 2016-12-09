#ifndef COMPARATOR_ABSTRACT_HPP
#define COMPARATOR_ABSTRACT_HPP

class Element;
class Number;
class Wall;

class Comparator_abstract
{
  public:
    virtual bool compare_number_with_element(Number *n, Element *e1) = 0;
    virtual bool compare_number_with_number(Number *n, Number *e1) = 0;
    virtual bool compare_number_with_wall(Number *n, Wall *e1) = 0;

    virtual bool compare_wall_with_element(Wall *w, Element *e1) = 0;
    virtual bool compare_wall_with_wall(Wall *w, Wall *e1) = 0;
    virtual bool compare_wall_with_number(Wall *w, Number *e1) = 0;

    virtual bool compare_element_with_element(Element *e0, Element *e1) = 0;
};

#endif