#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "banana.hpp"

using namespace std;

Banana::Banana()
{
    FallingObject::image.setImageFile("images/banana.jpeg");
    PointCarryItem::setPoint(10);
}
