#ifndef HEADERBAR_H
#define HEADERBAR_H

#include "Location.hpp"
#include "PointCarryItem.hpp"

class HeaderBar
{
private:
	Location marks1;
	PointCarryItem *item1;
	int totalMarks, font;

public:
	HeaderBar(int =0, int =0, int =0, int =0);
	void marksInProgress(); //for marks during the game progress
	void marksOutput(); //final marks
	void setLocation(int =0, int =0);
	void setFont(int f);
	void setMarks(int =0);
	int getMarks();
	void assignMarks(PointCarryItem * = NULL);
	void plusMinusMarks();
	int getX() const;
    int getY() const;
};

#endif
