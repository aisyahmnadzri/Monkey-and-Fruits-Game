#ifndef PLAYER_H
#define PLAYER_H

#include "Image.hpp"

class Player
{
private:
    Image image;
    int movement;

public:
    Player(int = 0, int = 0, int = 100, int = 120);
    void draw();
    void undraw();
    void move();
    void reverse();
    void showImage();

    int getLeft() const;
    int getRight() const;
    int getTop() const;
    int getHeight() const;
    int getMovement() const;

    void setPosition(int, int);
    void setMovement(int);
};

#endif