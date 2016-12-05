class State;

class Element
{
  public:
    virtual void draw() = 0;
    virtual ~Element(){};

  private:
    State *parent;
    int position;
};