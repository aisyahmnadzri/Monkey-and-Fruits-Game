#ifndef LOCATION_H
#define LOCATION_H

class Location
{
    private:
        int x, y;

    public:
        Location(int = 0, int = 0);
        void setX(int value);
        void setY(int value);
        void setPosition(int, int);
        int getX() const;
        int getY() const;
};

#endif