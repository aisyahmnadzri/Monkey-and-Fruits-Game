#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "FallingObject.hpp"

class GameOver : public FallingObject
{
    protected:
        int game;
    
    public:
        GameOver();
        void setGame(int = 0);
        int getGame() const;
};

#endif