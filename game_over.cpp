#include <iostream>
#include <graphics.h>
#include "game_over.hpp"

using namespace std;

GameOver::GameOver() : FallingObject()
{
    setSpeed(30);
}

void GameOver::setGame(int g)
{
    game = g;
}

int GameOver::getGame() const
{
    return game;
}