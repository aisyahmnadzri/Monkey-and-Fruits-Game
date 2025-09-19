#include <graphics.h>
using namespace std;

class Game
{
    private:
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

    setfillstyle(SOLID_FILL,WHITE); // create BLACK background color
    bar(0,0,screenWidth, screenHeight);

    system("pause");
    return 0;

}

Game::Game(int _x = 0, int _y = 0, int _w=100 , int _h=100 ) 
{
    x = _x;
    y = _y;
    w = _w;
    h =_h;
}


int Game::x1() const { return x; }
int Game::x2() const { return x+w; }
int Game::y1() const { return y; }
int Game::y2() const { return y+h; }
