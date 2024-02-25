#include <SFML/Graphics.hpp>
<<<<<<< HEAD
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
=======

#include <iostream>

#define ItemMenu 3
using namespace sf;

class Menugame
{
private:
    int selectitem = 0;
    Font font;
    Text menu[ItemMenu];

public:
    Menugame(float width, float height);
    virtual ~Menugame();

    int getPressed() { return selectitem; }
    void render(RenderTarget& target);
    void moveup();
    void movedown();
};

Menugame::Menugame(float width, float height)
{
    if (!font.loadFromFile("C:/Users/User/Desktop/gamenaja/main/font/Sobiscuit.otf")) {
        std::cout << "error";
    }

    for (int i = 0; i < ItemMenu; ++i)
    {
        menu[i].setFont(font);
        menu[i + 1].setFillColor(Color::White);
        menu[i].setOrigin(menu[i].getLocalBounds().width / 2, menu[i].getLocalBounds().height / 2);
        menu[i].setPosition(Vector2f(width / 2, height / (ItemMenu + 1) * (i + 1)));
    }

    menu[0].setFillColor(Color::Red);
    menu[0].setString("PLAYGAME");
    menu[1].setString("OPTIONS");
    menu[2].setString("EXIT");
}

Menugame::~Menugame()
{
}

void Menugame::render(RenderTarget& target)
{
    for (int i = 0; i < ItemMenu; ++i)
    {
        target.draw(menu[i]);
    }
}

void Menugame::moveup()
{
    if (selectitem - 1 >= 0)
    {
        menu[selectitem].setFillColor(Color::White);
        selectitem--;
        menu[selectitem].setFillColor(Color::Red);
    }
}

void Menugame::movedown()
{
    if (selectitem + 1 < ItemMenu)
    {
        menu[selectitem].setFillColor(Color::White);
        selectitem++;
        menu[selectitem].setFillColor(Color::Red);
    }
}
>>>>>>> 1ccb4fb8a4fa8b772ff858a853f05a3b3d6ed14c
