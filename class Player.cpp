#ifndef PLAYER_H

#include <graphics.h>
#include <cstdlib>
#include <string>
using namespace std;


//?This programme is the class Player (monkey character) for Group 3: Monkey & Fruit game project

//Left arrow => to move the character to the left
//Right arrow => to move the character to the right

class Player
{
private:
    int coordinateX, coordinateY;
    int wideness, height;
    int movementRate;
    string imageFile;

public:
    Player();

    Player(int, int, int, int, int);
    
    void draw() const;
    void undraw() const;

    void motion(int position);
    void motion();

    int getHeight() const;
    double getForward() const;
    double getLeft() const;
    int getMovementRate() const;

    void setHeight(int _height);
    void setForward(int value);
    void setLeft(int _position);
    void setMovementRate(int value);
    
    void backwards();
};

Player::Player()
{
    coordinateX = 0;
    coordinateY = 0;
    wideness = 200;
    height = 236;
    movementRate = 0;
}

Player::Player(int _x, int _y, int _wideness, int _height, int speed)
{
    coordinateX = _x;
    coordinateY = _y;
    wideness = _wideness;
    height = _height;
    movementRate = speed;
    imageFile = "Monkey.jpg";
}

void Player::draw() const { readimagefile(imageFile.c_str(), coordinateX, coordinateY, coordinateX + wideness, coordinateY + height); }
void Player::undraw() const
{
     setfillstyle(SOLID_FILL, GREEN); 
     bar(coordinateX, coordinateY, coordinateX + wideness, coordinateY + height);
}

void Player::motion(int position) { coordinateX = coordinateX + position; }
void Player::motion() { coordinateX += movementRate; }

int Player::getHeight() const { return height; }
void Player::setHeight(int _height) { height = _height; }

double Player::getForward() const { return coordinateY; }
void Player::setForward(int value) { coordinateY = value; }

double Player::getLeft() const {return coordinateX;}
void Player::setLeft(int value) {coordinateX = value;}

int Player::getMovementRate() const {return movementRate;}
void Player::setMovementRate(int value) {coordinateX = value;}

void Player::backwards() { movementRate = -movementRate; }

int main()
{
    int screenWideness = getmaxwidth();
    int screenHeight = getmaxheight();

    Player monkey;

    int coordinatex = screenHeight - monkey.getHeight();
    int coordinatey = screenWideness / 2;

    monkey.setForward(coordinatex);
    monkey.setLeft(coordinatey);

    initwindow(screenWideness, screenHeight, "class Player");

    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, screenWideness, screenHeight);
    char character = 0;

    while (character != 27)
    {
        character = 0;

        monkey.draw();
        delay(500);
        monkey.undraw();
        monkey.motion();

        if (kbhit())
            character = getch();

        switch (toupper(character))
        {
        case KEY_RIGHT:
            monkey.draw();
            monkey.motion(5);
            monkey.undraw();
            break;

        case KEY_LEFT:
            monkey.draw();
            monkey.motion(-5);
            monkey.undraw();
            break;

        }
    }

    return 0;
}
