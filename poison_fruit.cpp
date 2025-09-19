#include <iostream>
#include <graphics.h>
#include "PointCarryItem.hpp"
#include "poison_fruit.hpp"

using namespace std;

PoisonFruit::PoisonFruit()
{
    FallingObject::image.setImageFile("images/poison_fruit.jpg");
    GameOver::setGame(-1);
}

