// pac-man.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

using namespace std;
using namespace sf;


int main()
{

    Game game;

    while (game.running())
    {
        game.update();
        game.render();

    }
    return 0;
}

