#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
private:
	float moveSpeed;
	int hpplayer;
	Texture player;
	Sprite playergame;
public:
	Player();
	virtual ~Player();

	void move(Vector2f direction);
	void update();
	void render(RenderTarget& Target);
};

Player::Player() {
	player.loadFromFile("C:/Users/User/Desktop/gamenaja/main/pngremo.png");
	playergame.setTexture(player);
	moveSpeed = 5.0f;
}
Player::~Player()
{

}

void Player::move(Vector2f direction) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playergame.move(moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playergame.move(-moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playergame.move(0.f, -moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playergame.move(0.f, moveSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::q)) {

	}
}

void Player::update() {
	
}

void Player::render(RenderTarget& Target) {
	Target.draw(playergame);
}



