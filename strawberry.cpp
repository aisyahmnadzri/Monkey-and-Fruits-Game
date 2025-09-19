#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "strawberry.hpp"

using namespace std;

Strawberry::Strawberry()
{
    FallingObject::image.setImageFile("images/strawberry.jpeg");
    PointCarryItem::setPoint(10);
}
