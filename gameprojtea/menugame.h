#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Game.h"
using namespace sf;

class Button
{
public:
	Button(float x, float y, float width, float height, Color beforepress, Color afterpress);
	virtual ~Button();

	bool Mouse(RenderWindow& window);
	void update(RenderWindow& window);
	void render(RenderWindow& window);
private:
	RectangleShape button;
	Color beforepress;
	Color afterpress;
	Text text;
};

Button::Button(float x, float y, float width, float height, Color beforepress, Color afterpress) : beforepress(beforepress), afterpress(afterpress)
{
	button.setPosition(Vector2f(x, y));
	button.setSize(Vector2f(width, height));
	button.setFillColor(beforepress);
}

Button::~Button()
{
}

bool Button::Mouse(RenderWindow& window) {
	Vector2i mousePosition = Mouse::getPosition(window);
	FloatRect buttonBounds = button.getGlobalBounds();

	return buttonBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

void Button::update(RenderWindow& window) {
	if (Mouse(window)) {
		button.setFillColor(afterpress);
	}
	else {
		button.setFillColor(beforepress);
	}
}

void Button::render(RenderWindow& window) {
	window.draw(button);
	window.draw(text);
}

class Menu
{
public:
	Menu();
	~Menu();

	void handleInput(RenderWindow& window);
	void update(RenderWindow& window);
	void render(RenderWindow& window);
private:
	Button NewGame;
	Button Setting;
	Button ExitGame;
	Game game;
};

Menu::Menu()
{

}

Menu::~Menu()
{
}

void Menu::handleInput(RenderWindow& window) {

}

void Menu::update(RenderWindow& window) {
	NewGame.update(window);
	Setting.update(window);
	ExitGame.update(window);
}

void Menu::render(RenderWindow& window) {
	NewGame.render(window);
	Setting.render(window);
	ExitGame.render(window);
}