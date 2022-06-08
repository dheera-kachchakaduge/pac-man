#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"

#include "Player.h"

using namespace std;
using namespace sf;

class Game
{
private:
	Event e;
	RenderWindow* window;

	void initVariables();
	void initWindow();

public:

	Player pacMan;

	Game();
	~Game();

	void pollEvents();
	void update();
	void render();

	const bool running();

};

