#include "Game.h"
using namespace sf;

void Game::mainwindow() {
	this->window = new RenderWindow(VideoMode(900, 800), "HeeYAi");
}

Game::Game()
{
	this->mainwindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateEvent()
{
	while (this->window->pollEvent(this->sfevent))
	{
		if (this->sfevent.type == Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update()
{
	this->updateEvent();
}

void Game::rander()
{
	this->window->clear();
	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->rander();
	}
}
