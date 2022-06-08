#include "Player.h"


Player::Player()
{
	initSprite();
}

Player::~Player()
{
	
}

void Player::initSprite()
{
	this->pacManCloseTexture.loadFromFile("textures/pc-close.png");

	this->pacManOpenTexture.loadFromFile("textures/pc-open.png");
	this->pacManOpenDown.loadFromFile("textures/pc-open-down.png");
	this->pacManOpenUp.loadFromFile("textures/pc-open-up.png");
	this->pacManOpenLeft.loadFromFile("textures/pc-open-left.png");


	this->pacManMidTexture.loadFromFile("textures/pc-mid.png");
	this->pacManMidDown.loadFromFile("textures/pc-mid-down.png");
	this->pacManMidUp.loadFromFile("textures/pc-mid-up.png");
	this->pacManMidLeft.loadFromFile("textures/pc-mid-left.png");


	this->pacManSprite.setTexture(pacManCloseTexture);
	this->pacManSprite.setScale(0.16, 0.16);
}

void Player::update()
{

}

void Player::turningSprite() 
{
	float x = pacManSprite.getGlobalBounds().left;
	float y = pacManSprite.getGlobalBounds().top;

	if (fmod(x, 80) == 0.0 && fmod(y, 80) == 0.0)
	{
		turnPossible = true;
	}

	if (turning) 
	{
		if (turnPossible)
		{
			this->direction = turningDirection;
		}
	}

	turnPossible = false;
	
}

void Player::moveSprite()
{
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (this->direction == 3 || this->direction == 4)
		{
			turning = true;
			turningDirection = 1;
			turningSprite();
		}
		else this->direction = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (this->direction == 3 || this->direction == 4) 
		{
			turning = true;
			turningDirection = 2;
			turningSprite();
		}
		else this->direction = 2;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (this->direction == 1 || this->direction == 2) 
		{
			turning = true;
			turningDirection = 3;
			turningSprite();
		}
		else this->direction = 3;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (this->direction == 1 || this->direction == 2) 
		{
			turning = true;
			turningDirection = 4;
			turningSprite();
		}
		else this->direction = 4;
	}

	if (this->direction == 1)
	{
		this->pacManSprite.move(-3, 0);
	}
	else if (this->direction == 2)
	{
		this->pacManSprite.move(3, 0);
	}
	else if (this->direction == 3)
	{
		this->pacManSprite.move(0, -3);
	}
	else if (this->direction == 4)
	{
		this->pacManSprite.move(0, 3); 
	}
}



void Player::changeTexture()
{
	if (mouthState == 0) // pacManCloseTexture
	{
		if (this->direction == 1)
		{
			this->pacManSprite.setTexture(pacManOpenLeft);
		}
		else if (this->direction == 2)
		{
			this->pacManSprite.setTexture(pacManOpenTexture);
		}
		else if (this->direction == 3)
		{
			this->pacManSprite.setTexture(pacManOpenUp);
		}
		else if (this->direction == 4)
		{
			this->pacManSprite.setTexture(pacManOpenDown);
		}
		mouthState = 1;
	}
	else if (mouthState == 1) // pacManCloseTexture
	{
		if (this->direction == 1)
		{
			this->pacManSprite.setTexture(pacManMidLeft);
		}
		else if (this->direction == 2)
		{
			this->pacManSprite.setTexture(pacManMidTexture);
		}
		else if (this->direction == 3)
		{
			this->pacManSprite.setTexture(pacManMidUp);
		}
		else if (this->direction == 4)
		{
			this->pacManSprite.setTexture(pacManMidDown);
		}
		
		mouthState = 2;
	}
	else if (mouthState == 2) // pacManCloseTexture
	{
		pacManSprite.setTexture(pacManCloseTexture);
		mouthState = 0;
	}
}

void Player::cycleTextures()
{
	cycleCounter++;
	if (cycleCounter == 14) {
		changeTexture();
		cycleCounter = 0;
	}
}

void Player::windowCollision()
{
	
}


void Player::render(RenderTarget* target)
{
	target->draw(pacManSprite);
	cycleTextures();
	moveSprite();
}
