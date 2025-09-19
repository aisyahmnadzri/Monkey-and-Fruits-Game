#include <graphics.h>
#include <string>
using namespace std;

class FallingImageObject
{
private:
    int x, y, w, h;
    string imageFile;
    int speed;

public:
    FallingImageObject(string _file, int _x, int _y, int _w, int _h, int _speed);

    int x1() const;
    int x2() const;
    int y1() const;
    int y2() const;

    void draw() const;
    void undraw() const;
    void move();

    int getSpeed() const;
    void setSpeed(int value);
};

FallingImageObject::FallingImageObject(string _file, int _x = 0, int _y = 0, int _w = 100, int _h = 100, int _speed=0)
                    : imageFile(_file), x(_x), y(_y), w(_w), h(_h), speed(_speed) {}
int FallingImageObject::x1() const { return x; }
int FallingImageObject::x2() const { return x + w; }
int FallingImageObject::y1() const { return y; }
int FallingImageObject::y2() const { return y + h; }

void FallingImageObject::draw() const
{
    readimagefile(imageFile.c_str(), x1(), y1(), x2(), y2()); 
}

void FallingImageObject::undraw() const
{
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1(), y1(), x2(), y2());
}

void FallingImageObject::move() { y = y + speed; }

int FallingImageObject::getSpeed() const {return speed;}
void FallingImageObject::setSpeed(int value) { speed = value;}

class FallingPineapple : public FallingImageObject
{ public: FallingPineapple(int x, int y); };
class FallingGrape : public FallingImageObject
{ public: FallingGrape(int x, int y);};
class FallingBanana : public FallingImageObject
{ public: FallingBanana(int x, int y);};
class FallingCoin : public FallingImageObject
{ public:  FallingCoin(int x, int y);};
class FallingRottenFruit : public FallingImageObject
{ public: FallingRottenFruit(int x, int y);};
class FallingPoisonFruit : public FallingImageObject
{ public: FallingPoisonFruit(int x, int y);};

FallingPineapple::FallingPineapple(int x, int y) : FallingImageObject("images/pineapple.jpg", x, y, 100, 92) {}
FallingGrape::FallingGrape(int x, int y) : FallingImageObject("images/grape.jpg", x, y, 100, 82) {}
FallingBanana::FallingBanana(int x, int y) : FallingImageObject("images/banana.jpg", x, y, 100, 86) {}
FallingCoin::FallingCoin(int x, int y) : FallingImageObject("images/coin.jpg", x, y, 100, 88) {}
FallingRottenFruit::FallingRottenFruit(int x, int y) : FallingImageObject("images/rotten_fruit.jpg", x, y, 100, 79) {}
FallingPoisonFruit::FallingPoisonFruit(int x, int y) : FallingImageObject("images/poison_fruit.jpg", x, y, 100, 91) {}

#define COUNT 10

int main()
{

    FallingImageObject objects[ COUNT ] = {
        FallingImageObject("images/watermelon.jpg", 10, 0, 150, 75),
        FallingPineapple(200, 0),
        FallingGrape(300, 0),
        FallingBanana(400, 0),
        FallingPineapple(500, 0),
        FallingCoin(600, 0),
        FallingRottenFruit(700, 0),
        FallingPoisonFruit(800,0),
        FallingCoin(900, 0),
        FallingBanana(1000, 0)};

    objects[0].setSpeed(10);
    objects[1].setSpeed(5);
    objects[2].setSpeed(10);
    objects[3].setSpeed(20);
    objects[4].setSpeed(30);
    objects[5].setSpeed(15);
    objects[6].setSpeed(20);
    objects[7].setSpeed(10);
    objects[8].setSpeed(35);
    objects[9].setSpeed(5);

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    initwindow(screenWidth, screenHeight, "Falling Objects ");

    setfillstyle(SOLID_FILL,WHITE); 
    bar(0,0,screenWidth, screenHeight);
    char ch = 0;

    while (ch != 27)
    {
        ch = 0;

        for (int i=0; i<COUNT; i++) objects[i].draw();

        delay(200);
        
        for (int i=0; i<COUNT; i++) objects[i].undraw();
        for (int i=0; i<COUNT; i++) objects[i].move();

        if (kbhit())
            ch = getch();

    }

    return 0;
}

