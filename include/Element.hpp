#ifndef ELEMENT_HPP
#define ELEMENT_HPP

class Comparator_abstract;

class Element
{
  public:
    Element(Comparator_abstract &c);
    virtual bool compare(Element *e);

  public:
    Comparator_abstract *comparator;
};

#endif