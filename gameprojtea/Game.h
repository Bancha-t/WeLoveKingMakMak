#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Game
{
private:
	RenderWindow window;
	Texture bg;
	Sprite bgg;
	Player player;

	void mainwindow(float width, float height);
	void loadbgg();
public:
	Game();
	virtual ~Game();

	//void update();
	void render(RenderWindow& window);
	void run();
};

void Game::mainwindow(float width, float height) {
	window.create(VideoMode(width, height), "Heeyaiyai");
}

void Game::loadbgg() {
	bg.loadFromFile("C:/Users/User/Desktop/gamenaja/main/png/mapnaja.jpg");
	bgg.setTexture(bg);
}

Game::Game() {
	loadbgg();
	mainwindow(1082, 739);
}

Game::~Game() {

}

void Game::render(RenderWindow& window) {
	window.clear();
	mainwindow(1082, 739);
	window.draw(bgg);
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
		player.render(window);
		window.display();
	}
}
