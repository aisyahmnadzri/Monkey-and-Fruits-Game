#include <iostream>
#include <graphics.h>
#include "FallingObject.hpp"

using namespace std;

FallingObject::FallingObject(int _x, int _y, int _w, int _h) : image(NULL, _x, _y, _w, _h), speed(0)
{
}
void FallingObject::draw() { image.draw(); } 
void FallingObject::undraw() { image.undraw(); }
void FallingObject::move() 
{ 
    image.move(0, speed); 
}

int FallingObject::getLeft() const { return image.getX(); }
int FallingObject::getRight() const { return image.getXplusWidth(); }
int FallingObject::getHeight() const { return image.getHeight(); }
int FallingObject::getTop() const { return image.getY();}
int FallingObject::getBottom() const {return image.getYplusHeight();}
int FallingObject::getSpeed() const { return speed; }

void FallingObject::setPosition(int v1, int v2) { image.setLocation(v1, v2); }
void FallingObject::setSpeed(int value) { speed = value; }