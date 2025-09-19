#ifndef FALLINGOBJECT_H
#define FALLINGOBJECT_H

#include "Image.hpp"

class FallingObject
{
    protected:
        Image image;
        int speed;

    public:
        FallingObject(int = 0, int = 0, int = 80, int = 100);
        void draw();
        void undraw();
        void move();
        
        int getLeft() const;
        int getRight() const;
        int getHeight() const;
        int getTop() const;
        int getBottom() const;
        int getSpeed() const;

        void setPosition(int, int);
        void setSpeed(int);

};

#endif