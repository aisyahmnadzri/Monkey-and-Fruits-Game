#include <iostream>
#include <graphics.h>
#include "Player.hpp"

using namespace std;

Player::Player(int _x, int _y, int _w, int _h) : image("images/monkey.jpeg", _x, _y, _w, _h), movement(0)
{}

void Player::draw() { image.draw(); }
void Player::undraw() { image.undraw(); }
void Player::move() 
{ 
    image.move(movement, 0); 
}
void Player::reverse() { movement = -movement; }

int Player::getLeft() const { return image.getX(); }
int Player::getRight() const { return image.getXplusWidth(); }
int Player::getTop() const { return image.getY();}
int Player::getHeight() const { return image.getHeight(); }
int Player::getMovement() const { return movement; }

void Player::setPosition(int v1, int v2) { image.setLocation(v1, v2); }
void Player::setMovement(int value) 
{ 
    movement = value; 
}