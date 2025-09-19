#include<iostream>
#include<Windows.h>
#include <graphics.h>

using namespace std;

class Bar 
{
    private:
        int marks;
        int times;
    
    public:
        int add();
        int substract();

};

int main() 
{
    char arr[2];
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "Time and Mark ");
    setcolor(10);
    settextstyle(2, HORIZ_DIR, 20);

    for (int time = 120; time >=0; time--)
    {
        
        sprintf(arr,"%d", time);
	    outtextxy(10,0,arr);
	    delay(1000);
        setcolor(WHITE);
   
    }
}

