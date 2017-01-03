#include "lib.hpp"
#include "Element.hpp"

#include <stdexcept>
#include <iostream>
#include <random>

using namespace z;
using namespace std;

/* Lire les commentaires dans lib.hpp pour toute information sur
    ses fonctions */

ElementPtr z::merge(Element *e0, Element *e1)
{
    if (auto e = e0->merge(e1))
	return e;
    else
	return e1->merge(e0);
}

bool z::is_equal(Element *e0, Element *e1)
{
    bool b;
    bool error = e0->is_equal(e1, b);

    if (error)
	error = e1->is_equal(e0, b);

    if (error)
	throw(std::runtime_error("Not Comparable Elements."));

    return b;
}

bool z::is_greater(Element *e0, Element *e1)
{
    bool b;
    bool error = e0->is_greater(e1, b);

    if (error)
	error = e1->is_greater(e0, b);
    else
	return b;

    if (error)
	throw(std::runtime_error("Not Comparable Elements."));
    else
	return !b;
}

void z::push_left(Grid &grid, Element_type brush)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int i = 0; i != m; ++i)
	for (int j = 0; j != n; ++j)
	    if (grid[i][j]->get_type() == brush)
		for (int k = j + 1; k != n; ++k)
		{
		    if (grid[i][k]->get_type() != brush)
		    {
			grid[i][j].swap(grid[i][k]);
			break;
		    }
		}
}

void z::merge_left(Grid &grid, Element *fill)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int i = 0; i != m; ++i)
	for (int j = 0; j != n - 1; ++j)
	    if (z::is_equal(grid[i][j].get(), grid[i][j + 1].get()))
	    {
		grid[i][j] = z::ElementPtr(z::merge(grid[i][j].get(), grid[i][j].get()));
		grid[i][j + 1] = fill->make_copy();
	    }
}

void z::push_right(Grid &grid, Element_type brush)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int i = 0; i != m; ++i)
	for (int j = n - 1; j != -1; --j)
	    if (grid[i][j]->get_type() == brush)
		for (int k = j - 1; k != -1; --k)
		{
		    if (grid[i][k]->get_type() != brush)
		    {
			grid[i][j].swap(grid[i][k]);
			break;
		    }
		}
}

void z::merge_right(Grid &grid, Element *fill)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int i = 0; i != m; ++i)
	for (int j = n - 1; j != 0; --j)
	    if (z::is_equal(grid[i][j].get(), grid[i][j - 1].get()))
	    {
		grid[i][j] = z::ElementPtr(z::merge(grid[i][j].get(), grid[i][j - 1].get()));
		grid[i][j - 1] = fill->make_copy();
	    }
}

void z::push_up(Grid &grid, Element_type brush)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int j = 0; j != n; ++j)
	for (int i = 0; i != m; ++i)
	    if (grid[i][j]->get_type() == brush)
		for (int k = i + 1; k != m; ++k)
		{
		    if (grid[k][j]->get_type() != brush)
		    {
			grid[i][j].swap(grid[k][j]);
			break;
		    }
		}
}

void z::merge_up(Grid &grid, Element *fill)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int j = 0; j != n; ++j)
	for (int i = 0; i != m - 1; ++i)
	    if (z::is_equal(grid[i][j].get(), grid[i + 1][j].get()))
	    {
		grid[i][j] = z::ElementPtr(z::merge(grid[i][j].get(), grid[i + 1][j].get()));
		grid[i + 1][j] = fill->make_copy();
	    }
}

void z::push_down(Grid &grid, Element_type brush)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int j = 0; j != n; ++j)
	for (int i = m - 1; i != -1; --i)
	    if (grid[i][j]->get_type() == brush)
		for (int k = i - 1; k != -1; --k)
		{
		    if (grid[k][j]->get_type() != brush)
		    {
			grid[i][j].swap(grid[k][j]);
			break;
		    }
		}
}

void z::merge_down(Grid &grid, Element *fill)
{
    int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int j = 0; j != n; ++j)
	for (int i = m - 1; i != 0; --i)
	    if (z::is_equal(grid[i][j].get(), grid[i - 1][j].get()))
	    {
		grid[i][j] = z::ElementPtr(z::merge(grid[i][j].get(), grid[i - 1][j].get()));
		grid[i - 1][j] = fill->make_copy();
	    }
}

void z::fill_with(Grid &grid, Element *fill)
{
	int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    for (int i = 0; i != m; ++i)
	for (int j = 0; j != n; ++j)
	    grid[i][j] = fill->make_copy();
}

z::Indice z::random_element(Grid& grid, z::Element_type type)
{
	int m = grid.size();    //line
    int n = grid[0].size(); //colomn

    Indice indice;

    std::random_device seed;     // seed
    std::mt19937_64 gen(seed()); // source of randomness

    uniform_int_distribution<int> distribution_colomn(0, n - 1); // colomn
    uniform_int_distribution<int> distribution_line(0, m - 1);   // line

    int i, j;
    for (int k = 0; k != n * m * 10; ++k)
    {
        i = distribution_line(gen);
        j = distribution_colomn(gen);

        if (grid[i][j]->get_type() == type)
        {
            indice.i = i;
            indice.j = j;
            return indice;
        }
    }

    indice.i = -1;
    indice.j = -1;
    return indice;
}