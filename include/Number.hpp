#ifndef ELEMENT_H
#define ELEMENT_H
#include "Element.hpp"
#endif

class Number : public Element
{
public:
  Number(int num);
  void draw();
  int getNum();
  ~Number() {}

private:
  int num;
};