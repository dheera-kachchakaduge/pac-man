#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"

#include <math.h>

using namespace std;
using namespace sf;


class Player
{
private:
	Texture pacManCloseTexture;

	Texture pacManOpenTexture;
	Texture pacManOpenDown;
	Texture pacManOpenUp;
	Texture pacManOpenLeft;

	Texture pacManMidTexture;
	Texture pacManMidDown;
	Texture pacManMidUp;
	Texture pacManMidLeft;

	Sprite pacManSprite;

public:

	int cycleCounter = 0; 
	int mouthState = 0;
	bool mouthOpening = true;
	
	bool turnPossible = false;
	bool turning = false;
	int turningDirection = 0;

	int queueDirection = 0;

	int direction = 2;

	Player();
	~Player();

	void initSprite();
	void moveSprite();
	void turningSprite();
	void changeTexture();
	void cycleTextures();
	void windowCollision();
	void update();
	void render(RenderTarget*);
	



};

