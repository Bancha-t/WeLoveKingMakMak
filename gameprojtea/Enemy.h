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
	//void returnenemydamage(int);
	//void returnenemyHP(int);
	//Enemy(int initialHealth):HP(initialHealth);
	virtual ~Enemy();
	int getDamage() const;
	void takeDamage(int);
	void reduceHealth(int damage){
		HP -= damage;
		if(HP<=0){
			delete this;
		}
	}
	void getHealth();
	void update(const Vector2f& playerPosition);
	void render(RenderTarget& target) const;
	Vector2f getPosition() const;
private:
	int HP;//Enemy's health points
	int HPMAX;
	int DAMAGE;
	int POINT;
	int NewHp; 
	float speedenemy;
	Texture enemytexture;
	Sprite enemy;

	void setenemy();
	void intvariables();
};
#endif // ENEMY_H

