#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "coin.hpp"

using namespace std;

Coin::Coin()
{
    FallingObject::image.setImageFile("images/coin.jpeg");
    PointCarryItem::setPoint(5);
}
