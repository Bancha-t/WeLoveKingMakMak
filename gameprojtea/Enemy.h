#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include "Player.h"
using namespace sf;

class Enemy
{
public:
	Enemy(float posx, float posy);
	virtual ~Enemy();
	void update(const Vector2f& playerPosition);
	void render(RenderTarget& target) const;
	Vector2f getPosition() const;
	int getDamage() const;
	int getHealth() const;
	sf::FloatRect getGlobalBounds() const;
	void reduceHealth(int amount);

private:
	int HP;
	int HPMAX;
	int DAMAGE;
	int POINT;
	int NewHp;
	int health;
	float speedenemy;
	Texture enemytexture;
	Sprite enemy;

	void setenemy();
	void intvariables();
};
#endif // ENEMY_H

