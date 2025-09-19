#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <string>
using namespace std;

// #include "background.hpp"
#include "headerBar.hpp"
#include "player.hpp"
#include "FallingObject.hpp"
#include "poison_fruit.hpp"
#include "grape.hpp"
#include "banana.hpp"
#include "rotten_fruit.hpp"
#include "strawberry.hpp"
#include "coin.hpp"

void menu()
{
    readimagefile("7.jpeg", 0, 0, getmaxwidth(), getmaxheight());
    readimagefile("images/gametitle.jpg", getmaxwidth()*1/4, getmaxheight()*1/6, getmaxwidth()*3/4, getmaxheight()*1/2);
    readimagefile("images/start_button.jpeg", getmaxwidth()*1/3, getmaxheight()*4/7, getmaxwidth()*2/3, getmaxheight()*5/7);
}

void play()
{
    srand(time(0));

    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

    bool gamesuccess = true;

    time_t start, now;
    time(&start);

    int timePassed = 0;
    int size = 0;

    delay(2000);
    setfillstyle(SOLID_FILL,BLACK); // create BLACK background color
    bar(0,0,screenWidth, screenHeight);

    HeaderBar h_bar(50, 30, 0, 0);

    Player player;
    int y = screenHeight - player.getHeight()-20;
    int x = screenWidth / 2;
    player.setPosition(x, y);

    Coin coin[100];
    for(int i=0; i<100; i++)
    {
        coin[i].setPosition(100+rand()%1200, 70);
    }

    Banana banana[100];
    for(int i=0; i<100; i++)
    {
        banana[i].setPosition(200+rand()%1200, 70);
    }

    Grape grape[100];
    for(int i=0; i<100; i++)
    {
        grape[i].setPosition(300+rand()%1100, 70);
    }

    Strawberry strawberry[100];
    for(int i=0; i<100; i++)
    {
        strawberry[i].setPosition(70+rand()%1200, 70);
    }

    RottenFruit rottenFruit[100];
    for(int i=0; i<100; i++)
    {
        rottenFruit[i].setPosition(50+rand()%1300, 70);
    }

    PoisonFruit poison[150];
    for(int i=0; i<150; i++)
    {
        poison[i].setPosition(50+rand()%1300, 70);
    }

    PointCarryItem *p[600];
    for(int i=0, j=0; i<600 && j<100; i+=6, j++)
    {
        p[i]=&coin[j];
        p[i+1]=&banana[j];
        p[i+2]=&grape[j];
        p[i+3]=&strawberry[j];
        p[i+4]=&rottenFruit[j];
        p[i+5]=&banana[j];
    }

    GameOver *G[150];
    for(int i=0, j=0; i<150 && j<150; i++, j++)
    {
        G[i]=&poison[j];
    }

    char key = 0;
    int count = 0;
    int n = 0;
    int indexp = 0, indexG = 0; //indexp = index for PointCarryItem , indexG = index for GameOver
    int timelimit = 120; //! time limit for one game

    while (true)
    {
        while(key != 27 && timePassed < timelimit && gamesuccess) 
        {
            key = 0;
            time(&now);
            timePassed = difftime(now, start);

            delay(1);
            string t = "Time: " + to_string(timePassed) + " seconds";
            settextstyle(10, HORIZ_DIR, 0);
            outtextxy(x-150, 30, (char*)t.c_str());

            h_bar.marksInProgress();

            player.draw();
            delay(100);
            player.undraw();
            player.move();

            for(int i= indexp; i<indexp+6; i++)
            {
                p[i]->draw();
            }
            delay(100);
            for(int i= indexp; i<indexp+6; i++)
            {
                p[i]->undraw();
            }
            for(int i= indexp; i<indexp+6; i++)
            {
                p[i]->move();
                
                if((p[i]->getBottom()>=y&&p[i]->getTop()<y)&&((p[i]->getLeft()>=player.getLeft()&&p[i]->getLeft()<=player.getRight())||(p[i]->getRight()>=player.getLeft()&&p[i]->getRight()<player.getRight())))
                {
                    h_bar.assignMarks(p[i]);
                    h_bar.plusMinusMarks();
                }
            }
            count++;
            if(count%20==0)
            indexp+=6;

            // if(count%4==0)
            G[indexG]->draw();
            delay(100);
            G[indexG]->undraw();
            G[indexG]->move();
            if((G[indexG]->getBottom()>=y&&G[indexG]->getTop()<y)&&((G[indexG]->getLeft()>=player.getLeft()&&G[indexG]->getLeft()<=player.getRight())||(G[indexG]->getRight()>=player.getLeft()&&G[indexG]->getRight()<player.getRight())))
            {
                if(G[indexG]->getGame()==-1) //! if touched poison fruit, game over
                gamesuccess = false;     
            }
            if(count%20==0) //从上到下大概是20个格子 所以到了第20格的时候会refresh新一轮
            indexG+=1;

            if ((player.getRight() >= screenWidth) || (player.getLeft() <= 0)) //! to prevent the monkey to come out of the screen
                player.reverse();

            if (kbhit())
            {
                key = getch();
                if (key == 0)
                    key = getch();
            }

            switch (toupper(key))
            {
            case KEY_LEFT:
                player.undraw();
                player.setMovement(-80);
                player.draw();
                break;

            case KEY_RIGHT:
                player.undraw();
                player.setMovement(80);
                player.draw();
                break;
            }
        } 
        if(timePassed >= timelimit || !gamesuccess) break;
    }

    if(gamesuccess && h_bar.getMarks()>=0)
    {
        h_bar.marksInProgress();
        readimagefile("images/win.jpg", getmaxwidth()*1/4, getmaxheight()*1/4, getmaxwidth()*3/4, getmaxheight()*3/4);
    }
    else if(!gamesuccess || h_bar.getMarks()<0)
    readimagefile("images/lose.jpg", getmaxwidth()*1/4, getmaxheight()*1/4, getmaxwidth()*3/4, getmaxheight()*3/4);

}



int main()
{
    char key;
    // creating the window
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Monkey & Fruits");

    setmousequeuestatus(WM_LBUTTONDOWN);
    int x, y;

    menu();

    while(key!=27)
    {
        key = 0;

        if (kbhit())
        {
             key = getch();
        }
        else
        key = 0;
        
        while(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if(x>getmaxwidth()*1/3 && x<getmaxwidth()*2/3 && y>getmaxheight()*4/7 && y<getmaxheight()*5/7)
            play();
        }
    }
}
