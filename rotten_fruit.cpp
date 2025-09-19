#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "rotten_fruit.hpp"

using namespace std;

RottenFruit::RottenFruit()
{
    FallingObject::image.setImageFile("images/rottenfruit.jpg");
    PointCarryItem::setPoint(-10);
}
