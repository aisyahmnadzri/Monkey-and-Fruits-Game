#include <graphics.h>
#include <cstdlib>
#include <string>
using namespace std;

class Rect
{
    private:
    int x, y, size;

    public:
    Rect(int _x, int _y, int _size); //constructor

    void setX(int value);
    void setY(int value);
    void setSize(int value);;
    int getX() const;
    int getY() const;
    int getSize() const;

};

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "This is to get location and size ");

    return 0;
}

Rect::Rect(int _x = 0, int _y = 0, int _size = 0)
{
    x = _x;
    y = _y;
    size = _size;
}

int Rect::getX() const { return x; }
int Rect::getY() const { return y; }
int Rect::getSize() const { return size; }
void Rect::setX(int value) { x = value; }
void Rect::setY(int value) { y = value; }
void Rect::setSize(int value) { size = value; }