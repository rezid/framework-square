#include <vector>
#include <memory>
#include <algorithm>

#ifndef ELEMENT_H
#define ELEMENT_H
#include "Element.hpp"
#endif



using namespace std;

class State : public vector<unique_ptr<Element>>
{
  public:
    State();
    State(int *parent);
    State(int n, unique_ptr<Element> element);

    State(State &s);

    State &operator=(State s);

  private:
    int *parent;
};