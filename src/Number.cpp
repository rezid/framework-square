#include "Number.hpp"
#include <iostream>

Number::Number(int n) : num{n} {}

void Number::draw() 
{
	std::cout << num;
}

int Number::getNum()
{
	return num;
}