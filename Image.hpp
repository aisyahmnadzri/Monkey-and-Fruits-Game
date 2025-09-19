#ifndef IMAGE_H
#define IMAGE_H

#include "Location.hpp"

class Image
{
    private:
        Location point;
        int width, height;
        char* imageFile;

    public:
        Image(char*, int = 0, int = 0, int = 0, int = 0);
        void setImageFile(char*);
        void setDimension(int, int);
        void setLocation(int, int);
        void setWidth(int);
        void setHeight(int);
        void draw();
        void undraw();
        void move(int, int);
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        int getXplusWidth() const;
        int getYplusHeight() const;
};

#endif