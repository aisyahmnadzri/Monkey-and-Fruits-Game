#include <graphics.h>
#include <cstdlib>
#include <string>

#define COUNT 10

class EarningPoint
{
    private:
    int fruits;
    int coins;

    public:
    EarningPoint();
    
    EarningPoint(int, int);

    int getFruits() const;
    int getCoins() const;

    int setFruits();
    int setCoins();

    int getAddPoint() const;
    void setAddPoint(int point);
};

EarningPoint::EarningPoint()
{
    fruits = 0;
    coins = 0;
}

EarningPoint::EarningPoint(int Fruits, int Coins)
{
    fruits = Fruits;
    coins = Coins;
}

int main()
{
    EarningPoint items;
    
    int i, count;
    int freshFruits, yellowCoins;
    int earningItems;

    items.getFruits;
    items.getCoins;

    while(i!=0)
    {
        if(earningItems = freshFruits)
           return 10;
        if(earningItems = yellowCoins);
           return 5; 

        exit(0);
    }

    return 0;
}

