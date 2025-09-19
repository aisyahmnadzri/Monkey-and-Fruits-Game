#include <graphics.h>
#include <iostream>
#include <string>
#include "HeaderBar.hpp"

using namespace std;

HeaderBar::HeaderBar(int _x, int _y, int f, int p)  
{
	marks1.setPosition(_x, _y); //from class location - rect.cpp/rect.hpp
	font = f;
    totalMarks = p;
}

void HeaderBar::setLocation(int _x, int _y)
{
    marks1.setPosition(_x, _y);
}

void HeaderBar::setFont(int f)
{
	font = f;
}

void HeaderBar::setMarks(int m)
{
	totalMarks = m;
}

int HeaderBar::getMarks()
{
	return totalMarks;
}

void HeaderBar::assignMarks(PointCarryItem *_item)
{
	item1 = _item;
}

void HeaderBar::plusMinusMarks()    //to update our marks during game - adition / subtract (+/-)
{
	totalMarks += item1->getPoint();    //to know the marks of the item
}

int HeaderBar::getX() const
{
    return marks1.getX();
}

int HeaderBar::getY() const
{
    return marks1.getY();
}

void HeaderBar::marksInProgress()
{
	string marks = "Marks: " + to_string(totalMarks) + "    ";  //to display the marks during game
	settextstyle(10, HORIZ_DIR, font); 
    outtextxy(getX(), getY(), (char*)marks.c_str());
}

// void HeaderBar::marksOutput()   //to display the final marks
// {
// 	string marks = "Congratulation, your final marks is " + to_string(totalMarks);
// 	settextstyle(10, HORIZ_DIR, font); 
//     outtextxy(getX(), getY(), (char*)marks.c_str());
// }