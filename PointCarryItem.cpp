#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"

using namespace std;

PointCarryItem::PointCarryItem():FallingObject()
{
    setSpeed(30);
}

void PointCarryItem::setPoint(int p)
{
    point = p;
}

int PointCarryItem::getPoint() const
{
    return point;
}