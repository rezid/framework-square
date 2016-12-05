#include "State.hpp"
#include "ElementFactory.hpp"

State::State() {}
State::State(int *p) : parent{p} {}
State::State(int n, unique_ptr<Element> element) : vector<unique_ptr<Element>>()
{
    unique_ptr<ElementFactory> factory{new ElementFactory()}; // factory
    reserve(n);                                               // <- optional bit to improve performance

    for (int i = 0; i != n; ++i)
        emplace_back(factory->createElement(element.get()));
}

State::State(State &s) : vector<unique_ptr<Element>>()
{
    unique_ptr<ElementFactory> factory{new ElementFactory()};
    reserve(s.size()); // <- optional bit to improve performance

    for (auto &e : s)
        emplace_back(factory->createElement(e.get()));
}

State &State::operator=(State s)
{
    unique_ptr<ElementFactory> factory{new ElementFactory()}; // factory

    reserve(s.size()); // <- optional bit to improve performance

    for (auto &e : s)
        emplace_back(factory->createElement(e.get()));

    return *this;
}
