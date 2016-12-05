
#include <memory>
class Element;

class ElementFactory
{
  public:
    virtual Element *createElement(Element* elem);
};