#include <iostream>
#include <vector>

#include "Element.hpp"
#include "Number.hpp"
#include "Wall.hpp"
#include "Comparator.hpp"

using namespace std;

int main()
{
    vector<Element *> v;
    Comparator c;

    v.push_back(new Element(c));
    v.push_back(new Number(c));
    v.push_back(new Wall(c));

    v[1]->compare(v[1]);

    char d;
    cin >> d;
    return 0;
}
