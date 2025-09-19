#ifndef POINTCARRYITEM_H
#define POINTCARRYITEM_H

#include "FallingObject.hpp"

class PointCarryItem : public FallingObject
{
    protected:
        int point;
    
    public:
        PointCarryItem();
        void setPoint(int = 0);
        int getPoint() const;
};

#endif