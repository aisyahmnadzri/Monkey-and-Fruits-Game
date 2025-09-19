#include <iostream>
#include <graphics.h>
#include "Image.hpp"

using namespace std;

Image::Image(char* _imageFile, int _x, int _y, int w, int h)
{
    point.setPosition(_x, _y);
    imageFile = _imageFile;
    width = w;
    height = h;
}

void Image::setImageFile(char* _imageFile)
{
    imageFile = _imageFile;
}

void Image::setDimension(int w, int h)
{
    width = w;
    height = h;
}

void Image::setLocation(int _x, int _y)
{
    point.setPosition(_x, _y);
}

void Image::setWidth(int w)
{
    width = w;
}

void Image::setHeight(int h)
{
    height = h;
}

void Image::draw()
{
    readimagefile(imageFile, getX(), getY(), getXplusWidth(), getYplusHeight());
}

void Image::undraw()
{
   setfillstyle(SOLID_FILL, BLACK);
   bar(getX(), getY(), getXplusWidth()+5, getYplusHeight()+5);
}

void Image::move(int dx, int dy)
{
    int newX, newY;
    newX = getX() + dx;
    newY = getY() + dy;
    point.setX(newX);
    point.setY(newY);
}

int Image::getX() const
{
    return point.getX();
}

int Image::getY() const
{
    return point.getY();
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

int Image::getXplusWidth() const
{
    return getX() + width;
}

int Image::getYplusHeight() const
{
    return getY() + height;
}