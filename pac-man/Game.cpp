#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}


const bool Game::running()
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->e)) 
	{
		switch (this->e.type)
		{
		case Event::Closed:
			this->window->close();

		case Event::KeyPressed:
			if (this->e.key.code == Keyboard::Escape)
				this->window->close();

			break;
		}
	}
}

void Game::update()
{
	pacMan.turningSprite();
	this->pollEvents();
}

void Game::render()
{
	this->window->clear(Color(0, 0, 0));
	pacMan.render(this->window);
	this->window->display();
}

void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->window = new RenderWindow(VideoMode(1680, 1680), "");
	this->window->setFramerateLimit(144);
}

