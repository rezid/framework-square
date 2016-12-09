#include "Comparator.hpp"
#include <iostream>

using namespace std;

bool Comparator::compare_number_with_element(Number *n, Element *e1)
{
    cout << "Number + Element = possible\n";
    return false;
}
bool Comparator::compare_number_with_number(Number *n, Number *e1)
{
    cout << "Number + Number = possible\n";
    return false;
}
bool Comparator::compare_number_with_wall(Number *n, Wall *e1)
{
    cout << "Number + Wall = possible\n";
    return false;
}

bool Comparator::compare_wall_with_element(Wall *w, Element *e1)
{
    cout << "Wall + Element = possible\n";
    return false;
}
bool Comparator::compare_wall_with_wall(Wall *w, Wall *e1)
{
    cout << "Wall + Wall = possible\n";
    return false;
}

bool Comparator::compare_wall_with_number(Wall *w, Number *e1)
{
    cout << "Wall + Number = possible\n";
    return false;
}

bool Comparator::compare_element_with_element(Element *e0, Element *e1)
{
    cout << "element + element = not possible\n";
    return false;
}
