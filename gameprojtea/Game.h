#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Game
{
private:
	RenderWindow window;
	VideoMode videomode;
	Texture bg;
	Sprite bgg;
	Player player;

	void mainwindow();
	void loadbgg();
public:
	Game();
	virtual ~Game();

	void updateevent();
	void update();
	void render(RenderWindow& window);
	void run();
};

void Game::mainwindow() {
	window.create(VideoMode(700, 400), "Heeyaiyai");
}

void Game::loadbgg() {
	//bg.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/mapnaja.jpg");
	//bgg.setTexture(bg);
}

Game::Game() {
	loadbgg();
	mainwindow();
}

Game::~Game() {

}

void Game::updateevent() {
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window.close();
		}
	}
}
void Game::update() {
	updateevent();
}

void Game::render(RenderWindow& window) {
	window.clear();
	window.draw(bgg);
	player.render(window);
	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		render(window);
		window.display();
	}
}
