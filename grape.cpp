#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "grape.hpp"

using namespace std;

Grape::Grape()
{
    FallingObject::image.setImageFile("images/grape.jpeg");
    PointCarryItem::setPoint(10);
}
