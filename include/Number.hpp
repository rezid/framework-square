#ifndef NUMBER_HPP
#define NUMBER_HPP

class Wall;
#include "Element.hpp"


class Number : public Element
{
  public:
    Number(Comparator_abstract &c); 
    virtual bool compare(Element *e);   
    virtual bool compare(Number *e);   
    virtual bool compare(Wall *e);  
};

#endif