#ifndef LIB_HPP
#define LIB_HPP

#include <memory>
#include <vector>

namespace z
{

struct Indice
{
    int i;
    int j;
};

enum class Element_type
{
    ELEMENT,
    BLANK,
    POWER_OF_2
};

class Game;

class Cmd;

class Element;
class Blank;
class Number;
class Power_of_2;

//enum class Direction {UP, DOWN, RIGHT, LEFT};

using ElementPtr = std::unique_ptr<Element>;
using Grid = std::vector<std::vector<ElementPtr>>;
using CmdPtr = std::unique_ptr<Cmd>;
using Line_iterator = Grid::iterator;
using Element_iterator = std::vector<ElementPtr>::iterator;
using Reverse_element_iterator = std::vector<ElementPtr>::reverse_iterator;

ElementPtr merge(Element *e0, Element *e1);

bool is_equal(Element *e0, Element *e1);
bool is_greater(Element *e0, Element *e1);

void push_left(Grid& grid, Element_type brush);
void push_right(Grid& grid, Element_type brush);
void push_up(Grid& grid, Element_type brush);
void push_down(Grid& grid, Element_type brush);

void merge_left(Grid& grid, Element* fill);
void merge_right(Grid& grid, Element* fill);
void merge_up(Grid& grid, Element* fill);
void merge_down(Grid& grid, Element* fill);

void fill_with(Grid &grid, Element* fill);

z::Indice random_element(Grid& grid, z::Element_type type);

}

#endif