#include <iostream>
#include "Location.hpp"

using namespace std;

Location::Location(int _x, int _y)
{
    setPosition(_x, _y);
}

void Location::setX(int _x)
{
    x = _x;
}

void Location::setY(int _y)
{
    y = _y;
}

void Location::setPosition(int _x, int _y)
{
    x = _x;
    y = _y;
}

int Location::getX() const
{
    return x;
}

int Location::getY() const
{
    return y;
}

