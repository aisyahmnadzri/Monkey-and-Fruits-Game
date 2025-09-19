#include <graphics.h>
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

class Game
{
    private:
    Rect rects;
    int x,y,w,h;

    public:
    Game(int _x, int _y, int _w, int _h) ;

    int x1() const ;
    int x2() const ;
    int y1() const ;
    int y2() const ;

    void fillBackground() const{
        setfillstyle(SOLID_FILL,WHITE); // create BLACK background color
        bar(x1(), y1(), x2(), y2());       
    }

};

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Game ");

    setfillstyle(SOLID_FILL,WHITE); // create WHITE background color
    bar(0,0,screenWidth, screenHeight);

    system("pause");
    return 0;

}

Rect::Rect(int _x = 0, int _y = 0, int _size = 0)
{
    x = _x;
    y = _y;
    size = _size;
}

Game::Game(int _x = 0, int _y = 0, int _w=100 , int _h=100 ) 
{
    x = _x;
    y = _y;
    w = _w;
    h =_h;
}

int Rect::getX() const { return x; }
int Rect::getY() const { return y; }
int Rect::getSize() const { return size; }
void Rect::setX(int value) { x = value; }
void Rect::setY(int value) { y = value; }
void Rect::setSize(int value) { size = value; }

int Game::x1() const { return rects.getX(); }
int Game::x2() const { return rects.getX()+w; }
int Game::y1() const { return rects.getY(); }
int Game::y2() const { return rects.getY()+h; }